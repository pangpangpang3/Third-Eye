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
    m_imageLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    m_imageLabel->setFixedSize(150, 150);

    m_hLayout = new QHBoxLayout;
    m_hLayout->addStretch();
    m_hLayout->addWidget(m_imageLabel);
    m_hLayout->addStretch();


    m_Layout = new QVBoxLayout;
    m_Layout->addStretch();
    m_Layout->addLayout(m_hLayout);
    m_Layout->addStretch();

    setLayout(m_Layout);
}

void ImageWidget::initConnect() {

}

void ImageWidget::paintEvent(QPaintEvent *) {

    m_pix.load(m_imageUrl);

    qDebug() << "m_pix size:" << m_pix.size();
    m_imageLabel->setFixedSize(m_pix.width(), m_pix.height());
    this->setFixedSize(m_pix.width()+2, m_pix.height()+2);
    qDebug() << "imageWidget size:" << m_imageLabel->size()
             << "widget size: " << this->size();

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    if (m_pix.isNull()) {
        qWarning() << "Invalid format of pixmap!";
    } else {
        QRect imageRect = QRect(m_imageLabel->x(), m_imageLabel->y(), m_imageLabel->width(), m_imageLabel->height());
        painter.drawPixmap(imageRect, m_pix);
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
