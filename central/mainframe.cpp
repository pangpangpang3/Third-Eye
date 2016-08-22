#include <QDebug>

#include "mainframe.h"

MainFrame::MainFrame(QWidget *parent)
    : QFrame(parent)
{
    initUi();

}
MainFrame::~MainFrame()
{}
void MainFrame::initUi(){

    m_imageArea = new QScrollArea(this);
    m_imageArea->setStyleSheet("background-color: green;");
    m_imageArea->setAlignment(Qt::AlignCenter);
    m_imageArea->setWidgetResizable(true);
    m_imageWidget = new ImageWidget(this);

    this->setStyleSheet("background-color: rgba(205, 170, 125, 255);");
    m_imageArea->setWidget(m_imageWidget);

    m_thumbnailWidget = new QListWidget(this);
    m_thumbnailWidget->setStyleSheet("background-color: rgba(216, 191, 216, 255);");
    m_thumbnailWidget->setFixedWidth(COMMONVIEW::RIGHT_SIZEBAR_WIDTH);

//    this->setFixedSize(m_imageWidget->width()+m_thumbnailWidget->width(), m_imageWidget->height()+52);

    m_Layout = new QHBoxLayout(this);
    m_Layout->setMargin(0);
    m_Layout->setSpacing(0);
    m_Layout->addStretch();
    m_Layout->addWidget(m_imageArea);
    m_Layout->addStretch();
    m_Layout->addWidget(m_thumbnailWidget);

    setLayout(m_Layout);


    qDebug() << "MainFrame size:" << m_imageWidget->size();
}
void MainFrame::initConnection(){}
void MainFrame::initData() {}

void MainFrame::setSelectedImage(QString fileUrl) {
    m_url = fileUrl;
    m_imageWidget->setImage(m_url);
}

void MainFrame::resizeEvent(QResizeEvent *e) {
//    this->resize(this->sizeHint());
}
