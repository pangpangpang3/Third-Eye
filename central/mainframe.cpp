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
    m_imageLabel = new QLabel(this);
//    m_imageLabel->setStyleSheet("background-color: rgba(102, 205, 170, 255);");

    m_imageHLayout = new QHBoxLayout;
    m_imageHLayout->setMargin(0);
    m_imageHLayout->setSpacing(0);
    m_imageHLayout->addStretch();
    m_imageHLayout->addWidget(m_imageLabel);
    m_imageHLayout->addStretch();

    m_imageVLayout = new QVBoxLayout;
    m_imageVLayout->setMargin(0);
    m_imageVLayout->setSpacing(0);
    m_imageVLayout->addStretch();
    m_imageVLayout->addLayout(m_imageHLayout);
    m_imageVLayout->addStretch();


    m_thumbnailWidget = new QListWidget(this);
//    m_thumbnailWidget->setStyleSheet("background-color: rgba(119, 136, 153, 255);");
    m_thumbnailWidget->setFixedWidth(COMMONVIEW::RIGHT_SIZEBAR_WIDTH);

    m_Layout = new QHBoxLayout(this);
    m_Layout->setMargin(0);
    m_Layout->setSpacing(0);
    m_Layout->addLayout(m_imageVLayout);
    m_Layout->addWidget(m_thumbnailWidget);

    setLayout(m_Layout);
}
void MainFrame::initConnection(){}
void MainFrame::initData() {}

void MainFrame::setSelectedImage(QString fileUrl) {
    m_url = fileUrl;
}

void MainFrame::paintEvent(QPaintEvent *) {
    qDebug() << "The url of m_pix:" << m_url
             << m_imageLabel->size();

    m_pix = new QPixmap(m_url);
    QPixmap tmpPix = m_pix->scaled(QSize(m_imageLabel->width(), m_imageLabel->height()));
//    qDebug() << tmp_pix.size();
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    if (m_pix->isNull()) {
        qWarning() << "Invalid format of pixmap!";
    } else {
        painter.drawPixmap(m_imageLabel->x(), m_imageLabel->y(), tmpPix);
        update();
    }
}

void MainFrame::resizeEvent(QResizeEvent *e) {
//    this->resize(this->sizeHint());
}
