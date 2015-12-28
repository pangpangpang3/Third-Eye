#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QObject>

#include "central/mainframe.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void openFile();
protected:
    void resizeEvent();

public:
    void initUi();
    void initConnect();
    void createMenu();
    void createToolbar();
    void createSideBar();
    void addCentralWidget();

    MainFrame* m_centralWidget;
    QFileDialog* m_fileDialog;

    QAction* openAction;
    QAction* saveAction;
    QAction* saveAsAction;
    QAction* printAction;
};

#endif // MAINWINDOW_H
