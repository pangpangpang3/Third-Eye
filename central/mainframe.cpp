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

    m_imageArea->setWidgetResizable(true);
    m_imageWidget = new ImageWidget(this);

    m_imageArea->setWidget(m_imageWidget);
    m_imageArea->setAlignment(Qt::AlignCenter);
    m_thumbnailWidget = new ImageInfoWidget(this);


    m_Layout = new QHBoxLayout(this);
    m_Layout->setContentsMargins(0, 0, 0, 0);
    m_Layout->setSpacing(0);
    m_Layout->addWidget(m_imageArea);
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
