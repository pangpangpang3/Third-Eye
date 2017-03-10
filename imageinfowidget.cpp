#include "side/imageinfowidget.h"
#include "common/constants.h"
#include "exif/exifutil.h"

#include <QLabel>

ImageInfoWidget::ImageInfoWidget(QWidget *parent)
    : QFrame(parent) {

    this->setStyleSheet("background-color: rgba(216, 191, 216, 255);");
    this->setFixedWidth(COMMONVIEW::RIGHT_SIZEBAR_WIDTH);
    m_Layout = new QGridLayout(this);
    m_Layout->setContentsMargins(10, 200, 10, 10);
    setLayout(m_Layout);
}

void ImageInfoWidget::setImage(QString &path) {
    auto infos = exif_image_url(path);
    QMapIterator<QString, QString> iterator(infos);
    while (iterator.hasNext()) {
        iterator.next();
        AddInfoPair(iterator.key(), iterator.value());
    }

}

void ImageInfoWidget::AddInfoPair(QString title, QString value) {
    QFont textFont;
    textFont.setPixelSize(12);
    QLabel* titleLabel = new QLabel(title, this);
    titleLabel->setFont(textFont);
    QLabel* valueLabel = new QLabel(value, this);
    valueLabel->setFont(textFont);
    int curRowCount = m_Layout->rowCount();

    m_Layout->addWidget(titleLabel, curRowCount, 0);
    m_Layout->addWidget(valueLabel, curRowCount, 1);
}

ImageInfoWidget::~ImageInfoWidget() {}
