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
//    setStyleSheet("background-color: rgba(255, 0, 0, 100);");
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
        m_img_actual_size = img.size();
        painter.setRenderHints(QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform);
        painter.drawPixmap(0, 0, width(), height(), img);

        update();
    }
}

void ImageWidget::setImage(QString url) {
    if (url.isEmpty())
        return;
    m_imageUrl = url;
    m_pix.load(m_imageUrl);
    //TODO: process if the image size is too large to display on screen
    if (m_pix.width() <=0 || m_pix.height() <= 0)
        return;
    else {
        this->setFixedSize(m_pix.width(), m_pix.height());
    }
    update();
}

void ImageWidget::wheelEvent(QWheelEvent *e) {
    //scale value be smalle
    if (e->angleDelta().y()<0) {
        if (qMin(this->width(), this->height()) >= 15) {
            this->setFixedSize(this->width()*0.95, this->height()*0.95);
        } else {
            //Todo: process the minsize
            this->setFixedSize(15, 15);
            return;
        }
    } else {
        if (qMin(this->width(), this->height()) >= 15) {
            this->setFixedSize(this->width()*1.05, this->height()*1.05);
        } else {
            //Todo: process the maxsize
            this->setFixedSize(15, 15);
            return;
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
