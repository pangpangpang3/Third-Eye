#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QStandardPaths>

#include "mainwindow.h"
#include "common/constants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initUi();
    initConnect();
}

void MainWindow::createMenu() {
    setMinimumSize(COMMONVIEW::MAIN_WINDOW_WIDTH,
                   COMMONVIEW::MAIN_WINDOW_HEIGHT);
    setWindowTitle("Third Eye");

    QMenu* imageMenu = menuBar()->addMenu(tr("Image(I)"));
    openAction = new QAction(tr("&open"), this);
    openAction->setShortcut(QKeySequence::Open);
    saveAction = new QAction(tr("save"), this);
    saveAsAction = new QAction(tr("save as"), this);
    printAction = new QAction(tr("print"), this);
    imageMenu->addAction(openAction);
    imageMenu->addAction(saveAction);
    imageMenu->addAction(saveAsAction);
    imageMenu->addAction(printAction);

    QMenu* editMenu = menuBar()->addMenu(tr("Edit"));
    QAction* rotate = new QAction(tr("rotate"), this);
    editMenu->addAction(rotate);

    this->menuBar()->setFixedHeight(30);
}
void MainWindow::addCentralWidget() {
    m_centralWidget = new MainFrame(this);
    this->setCentralWidget(m_centralWidget);
}
MainWindow::~MainWindow()
{
}

void MainWindow::initUi() {
    createMenu();
    addCentralWidget();
//    createToolbar();
//    createSideBar();
}

void MainWindow::openFile() {
    m_fileDialog = new QFileDialog(this);
    m_fileDialog->setDirectory("/home/ph/图片/");

    QStringList tmpPath =  QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    qDebug() << "standPaths:" << tmpPath.length();
    QUrl selectedFile = m_fileDialog->getOpenFileUrl(this, "Select one or more files to open",
                                                     tmpPath[0], COMMONVIEW::VALID_FORMAT);
    qDebug() << "selectedFileUrl" << selectedFile;
    QStringList tmpUrlList = selectedFile.toString().split("file://");
    m_centralWidget->setSelectedImage(tmpUrlList[1]);
}

void MainWindow::initConnect() {
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
}
