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
#include <QScrollArea>

#include "common/constants.h"
#include "imagewidget.h"
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
    void resizeEvent(QResizeEvent *e);
private:
    void initUi();
    void initConnection();
    void initData();

    QScrollArea* m_imageArea;
    ImageWidget* m_imageWidget;
    QHBoxLayout* m_imageHLayout;
    QVBoxLayout* m_imageVLayout;
//    QLabel* m_imageLabel;
    QString m_url = "";

    //The right size image
    QListWidget* m_thumbnailWidget;
    QPushButton* m_leftButton;
    QPushButton* m_rightButton;
    QHBoxLayout* m_Layout;
};

#endif // MAINFRAME

