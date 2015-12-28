#include <QDebug>

#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent)
    : QWidget(parent)
{
    initUI();
    initConnect();
}

void ImageWidget::initUI() {
    m_imageLabel = new QLabel(this);
    m_imageLabel->setStyleSheet("background-color: rgba(255, 205, 170, 255);");
    m_imageLabel->setFixedSize(150, 150);

    m_hLayout = new QHBoxLayout;
    m_hLayout->addStretch(1);
    m_hLayout->addWidget(m_imageLabel);
    m_hLayout->addStretch(1);


    m_Layout = new QVBoxLayout;
    m_Layout->addStretch(1);
    m_Layout->addLayout(m_hLayout);
    m_Layout->addStretch(1);

    setLayout(m_Layout);
}

void ImageWidget::initConnect() {

}

void ImageWidget::paintEvent(QPaintEvent *) {

    m_pix.load(m_imageUrl);

    qDebug() << "m_pix size:" << m_pix.size();
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    if (m_pix.isNull()) {
        qWarning() << "Invalid format of pixmap!";
    } else {
        painter.drawPixmap(0, 0, m_pix);
        update();
    }
}

void ImageWidget::setImage(QString url) {
    m_imageUrl = url;
    update();
}

void ImageWidget::resizeEvent(QResizeEvent *) {
    this->sizeHint();
    this->updateGeometry();
}

ImageWidget::~ImageWidget()
{}
