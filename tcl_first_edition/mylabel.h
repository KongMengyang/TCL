#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QWidget>
#include <QPoint>
#include <QDebug>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    int index=0;
    myLabel(QWidget *parent = 0);
    bool flag_start=false;
    QPoint points[24];
    bool pointActive[24]={false};
    bool pointSettled[24]={false};
    int selectedPoint=0;
    bool line_display=true;
    int currentWidth;
    int currentHeight;
    int lines[13][2]={{0,1},{2,3},{3,4},{3,5},{6,7},{3,8},{4,8},{2,9},{10,11},{12,13},{14,15},{16,17},{17,18}};

    bool displayall=false;
    bool flag_flow=true;
    int radius=50;
    int event_selected_dx=0;
    int event_selected_dy=0;
    bool displayhalo=true;


    QString marks[24]={"","","S","N","A","B","P","O","Po","Gn","Me","Go","UI","UIA","LI","LIA","Cm","Sn","UL","UL'","LL","LL'","EL1","EL2"};
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent*);
signals:
    void instructSignal(int index);
    void updateSignal();
private slots:

};

#endif // MYLABEL_H
