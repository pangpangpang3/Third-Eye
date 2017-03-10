#include "side/imageinfowidget.h"
#include "common/constants.h"

#include <QLabel>

ImageInfoWidget::ImageInfoWidget(QWidget *parent)
    : QFrame(parent) {

    this->setStyleSheet("background-color: rgba(216, 191, 216, 255);");
    this->setFixedWidth(COMMONVIEW::RIGHT_SIZEBAR_WIDTH);
    m_Layout = new QGridLayout(this);
    setLayout(m_Layout);
}

void ImageInfoWidget::AddInfoPair(QString title, QString value) {
    QLabel* titleLabel = new QLabel(title, this);
    QLabel* valueLabel = new QLabel(value, this);
    int curRowCount = m_Layout->rowCount();

    m_Layout->addWidget(titleLabel, curRowCount, 0);
    m_Layout->addWidget(valueLabel, curRowCount, 1);
}

ImageInfoWidget::~ImageInfoWidget() {}
