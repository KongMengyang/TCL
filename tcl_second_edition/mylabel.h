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
    int selectedPoint;
    bool line_display=true;
    int currentWidth;
    int currentHeight;

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
