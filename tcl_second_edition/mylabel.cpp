#include "mylabel.h"

myLabel::myLabel(QWidget *parent):QLabel(parent)
{
}
void myLabel::mousePressEvent(QMouseEvent* event)
{

    if(flag_start==false){
        return;
    }
    for(int i=0;i<index;i++)
    {
        int acc=5;
        if((points[i].x()-acc)<event->pos().x()&&event->pos().x()<(points[i].x()+acc)&&(points[i].y()-acc)<event->pos().y()&&event->pos().y()<(points[i].y()+acc))
        {
            selectedPoint=i;
            setMouseTracking(true);
            return;
        }
    }

    if(index<24)
    {
        points[index]=event->pos();
        update();
        index++;
        instructSignal(index);
    }
    else if(index==24){
        flag_start=false;
        update();
    }
    else
    {
        return;
    }
    /*
    if(hasMouseTracking()&&flag_point2==false)
    {

        point2=event->pos();
        flag_point2=true;
    }
    else if(hasMouseTracking()&&flag_point2==true)
    {
        setMouseTracking(false);
        flag_point3=true;
        flag_start=false;
        signal1();

    }
    else if(!hasMouseTracking()&&flag_point2==false)
    {
        point1 = point2 =point3= event->pos();
        setMouseTracking(true);
        update();
    }
    else
    {
        flag_point3=true;

    }*/
}

void myLabel::mouseMoveEvent(QMouseEvent* event)
{
    if(hasMouseTracking())
    {
        points[selectedPoint]=event->pos();
        update();
        updateSignal();
    }
}



void myLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(hasMouseTracking())
    {
        setMouseTracking(false);
    }
}

void myLabel::paintEvent(QPaintEvent* event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    QPen pen;                                 //创建一个画笔
    //画点
    pen.setColor(Qt::green);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawPoint(QPoint(0,0));
    for(int i=0;i<index;i++)
    {
        painter.drawPoint(points[i]);
    }
    //画点标记
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);
    for(int i=0;i<index;i++)
    {
        int x=points[i].x();
        int y=points[i].y();
        painter.drawText(QPoint(x+5,y),marks[i]);
    }
    //画线
    if(line_display==true){
        pen.setColor(Qt::yellow);
        pen.setWidth(2);
        painter.setPen(pen);
        if(index>1)//标准线
        {
            painter.drawLine(points[0],points[1]);
        }
        if(index>3)//SN线
        {
            painter.drawLine(points[2],points[3]);
        }
        if(index>4)//NA线
        {
            painter.drawLine(points[3],points[4]);
        }
        if(index>5)//NB线
        {
            painter.drawLine(points[3],points[5]);
        }
        if(index>7)//FH(P-O线)
        {
            painter.drawLine(points[6],points[7]);
        }
        if(index>8)//NP(N-Po)
        {
            painter.drawLine(points[3],points[8]);
        }
        if(index>8)//PA(Po-A)
        {
            painter.drawLine(points[4],points[8]);
        }
        if(index>9)//S-Gn
        {
            painter.drawLine(points[2],points[9]);
        }
        if(index>11)//Go-Me
        {
            painter.drawLine(points[11],points[10]);
        }
        if(index>13)//UI-UIA
        {
            painter.drawLine(points[12],points[13]);
        }
        if(index>15)//LI-LIA
        {
            painter.drawLine(points[14],points[15]);
        }
        if(index>17)//Cm-Sn
        {
            painter.drawLine(points[16],points[17]);
        }
        if(index>18)//Sn-UL
        {
            painter.drawLine(points[17],points[18]);
        }
    }




}




