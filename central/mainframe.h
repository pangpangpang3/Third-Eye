#ifndef MAINFRAME
#define MAINFRAME

#include <QFrame>
#include <QObject>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QPainter>
#include <QUrl>

#include "common/constants.h"
// MainFrame is the widgets contains the image body,and sideWidget with thumbnails

class MainFrame : public QFrame
{
    Q_OBJECT
public:
    MainFrame(QWidget* parent = 0);
    ~MainFrame();

public slots:
    void setSelectedImage(QString fileUrl);
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *e);
private:
    void initUi();
    void initConnection();
    void initData();

    QLabel* m_imageLabel;
    QString m_url = "";
    //The main pixmap
    QPixmap* m_pix = NULL;
    QHBoxLayout* m_imageHLayout;
    QVBoxLayout* m_imageVLayout;
    //The main pixmap size

    //The right size image
    QListWidget* m_thumbnailWidget;
    QPushButton* m_leftButton;
    QPushButton* m_rightButton;
    QHBoxLayout* m_Layout;
};

#endif // MAINFRAME

