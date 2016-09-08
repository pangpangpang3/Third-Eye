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

    connect(m_imageWidget, &ImageWidget::scaleSize, [=](QSize size) {
        Q_UNUSED(size);
        m_imageArea->sizeHint();
    });

    QVBoxLayout* imageVLayout = new QVBoxLayout;
    imageVLayout->setContentsMargins(0, 0, 0, 0);
    imageVLayout->setSpacing(0);
    imageVLayout->addStretch(1);
    imageVLayout->addWidget(m_imageWidget);
    imageVLayout->addStretch(1);

    QHBoxLayout* imageHLayout = new QHBoxLayout;
    imageHLayout->setContentsMargins(0, 0, 0, 0);
    imageHLayout->setSpacing(0);
    imageHLayout->addStretch(1);
    imageHLayout->addLayout(imageVLayout);
    imageHLayout->addStretch(1);

    m_imageArea->setLayout(imageHLayout);

    m_thumbnailWidget = new QListWidget(this);
    m_thumbnailWidget->setStyleSheet("background-color: rgba(216, 191, 216, 255);");
    m_thumbnailWidget->setFixedWidth(COMMONVIEW::RIGHT_SIZEBAR_WIDTH);

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
