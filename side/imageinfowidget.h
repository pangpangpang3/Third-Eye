#ifndef IMAGEINFOWIDGET_H
#define IMAGEINFOWIDGET_H

#include <QFrame>
#include <QGridLayout>

class ImageInfoWidget : public QFrame {
    Q_OBJECT
    public:
        ImageInfoWidget(QWidget* parent = 0);
        ~ImageInfoWidget();
public slots:
        void setImage(QString &path);
        void AddInfoPair(QString title, QString value);
private:
    QGridLayout* m_Layout;
};

#endif // IMAGEINFOWIDGET_H
