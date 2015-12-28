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
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
public slots:
    void setImage(QString url);
private:
    void initUI();
    void initConnect();

    QLabel* m_imageLabel;
    QString m_imageUrl = "";
    //The main pixmap
    QPixmap m_pix;
    QHBoxLayout* m_hLayout;
    QVBoxLayout* m_Layout;
    //The main pixmap size
};
#endif // IMAGEWIDGET

