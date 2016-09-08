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
    setFixedSize(640, 480);
    setStyleSheet("background-color: rgba(255, 0, 0, 100);");
    m_imageLabel = new QLabel(this);
}

void ImageWidget::initConnect() {

}

void ImageWidget::paintEvent(QPaintEvent *) {

    qDebug() << "m_pix paintEvent:" << m_pix.size();
    m_imageLabel->setMinimumSize(this->rect().size());
    m_imageLabel->sizeHint();
    qDebug() << m_imageLabel->size();
    QPainter painter(this);

    if (m_pix.isNull()) {
        qWarning() << "Invalid format of pixmap!";
    } else {
        QPixmap img = m_pix.scaled(rect().size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter.setRenderHints(QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform);
        if (img.width() < this->width())
            painter.drawPixmap((width() - img.width()) / 2, 0, img);
        else
            painter.drawPixmap(0, 0, img);
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
    //scale value be smalle
    if (e->angleDelta().y()<0) {
        if (qMin(this->width(), this->height()) >= 15) {
            this->setFixedSize(this->width()*0.95, this->height()*0.95);
        }
    } else {
        if (qMin(this->width(), this->height()) >= 15) {
            this->setFixedSize(this->width()*1.05, this->height()*1.05);

        }
    }

    update();
}

void ImageWidget::resizeEvent(QResizeEvent *) {
    this->sizeHint();
    this->updateGeometry();
    emit scaleSize(m_pix.size());
}

ImageWidget::~ImageWidget()
{}
