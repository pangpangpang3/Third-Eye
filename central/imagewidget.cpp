#include <QDebug>

#include "imagewidget.h"

const int IMAGE_MIN_WIDTH = 2;
const int IMAGE_MIN_HEIGHT = 2;

ImageWidget::ImageWidget(QWidget *parent)
    : QWidget(parent)
{
    initUI();
    initConnect();
}

void ImageWidget::initUI() {
    setStyleSheet("background:red;");
    m_imageLabel = new QLabel(this);
    m_imageLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    m_imageLabel->setMinimumSize(640, 480);
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

    qDebug() << "m_pix paintEvent:" << m_pix.size();

    m_imageLabel->setMinimumSize(m_pix.size());
    m_imageLabel->sizeHint();
    qDebug() << m_imageLabel->size();
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
    if (url.isEmpty())
        return;
    m_imageUrl = url;
    m_pix.load(m_imageUrl);
    qreal imgOriginWidth = m_pix.width();
    qreal imgOriginHeight = m_pix.height();

    QSize defaultSize = QSize(640, 480);
    m_pix = m_pix.scaled(defaultSize, Qt::KeepAspectRatio);
    qreal imgScaledWidth = m_pix.width();
    qreal imgScaledHeight = m_pix.height();

    m_scaleWidth = imgScaledWidth/imgOriginWidth;
    m_scaleHeight = imgScaledHeight/imgOriginHeight;

    update();
}

void ImageWidget::wheelEvent(QWheelEvent *e) {
    //scale value be smaller
    QSize originSize = m_pix.size();
    if (e->angleDelta().y()<0) {
        if (qMin(originSize.width(), originSize.height()) >= 15) {
            originSize = QSize(originSize.width() - 5, originSize.height() - 5);
            m_pix = m_pix.scaled(originSize, Qt::KeepAspectRatio);
        }
    } else {
        if (qMin(originSize.width(), originSize.height()) >= 15) {
            originSize = QSize(originSize.width() + 5, originSize.height() + 5);
            m_pix = m_pix.scaled(originSize, Qt::KeepAspectRatio);
        }
    }

    qDebug() << "m_pix wheelEvent:" << m_pix.size();
    update();
}

void ImageWidget::resizeEvent(QResizeEvent *) {

    this->sizeHint();
    this->updateGeometry();
}

ImageWidget::~ImageWidget()
{}
