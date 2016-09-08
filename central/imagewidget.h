#ifndef IMAGEWIDGET
#define IMAGEWIDGET

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>

class ImageWidget: public QWidget {
    Q_OBJECT
public:
    ImageWidget(QWidget* parent=0);
    ~ImageWidget();
signals:
    void scaleSize(QSize scaleSize);
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
public slots:
    void setImage(QString url);
protected:
    void wheelEvent(QWheelEvent *e);
private:
    void initUI();
    void initConnect();

    qreal m_scaleWidth;
    qreal m_scaleHeight;

    QLabel* m_imageLabel;
    QString m_imageUrl = "";
    //The main pixmap
    QPixmap m_pix;
    QSize m_img_actual_size = QSize(0, 0);
    QHBoxLayout* m_hLayout;
    QVBoxLayout* m_Layout;
    //The main pixmap size
};
#endif // IMAGEWIDGET

