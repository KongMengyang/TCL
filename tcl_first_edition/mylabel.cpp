#include "mylabel.h"

myLabel::myLabel(QWidget *parent):QLabel(parent)
{
}
void myLabel::mousePressEvent(QMouseEvent* event)
{

    if(flag_start==false){
        return;
    }
    if(displayall==true)
    {

        for(int i=0;i<24;i++)
        {
            int acc=5;
            if(pointSettled[i]==true){
                if((points[i].x()-acc)<event->pos().x()&&event->pos().x()<(points[i].x()+acc)&&(points[i].y()-acc)<event->pos().y()&&event->pos().y()<(points[i].y()+acc))
                {
                    selectedPoint=i;
                    setMouseTracking(true);
                    return;
                }
            }
        }

        if(flag_flow==true){
            if(index<24)
            {
                points[index]=event->pos();
                pointSettled[index]=true;
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
        }
    }
    else
    {
        for(int i=0;i<24;i++)
        {
            if(pointActive[i]==true){
                if((points[i].x()-event->pos().x())*(points[i].x()-event->pos().x())+(points[i].y()-event->pos().y())*(points[i].y()-event->pos().y())<=radius*radius)
                {
                    event_selected_dx=event->pos().x()-points[i].x();
                    event_selected_dy=event->pos().y()-points[i].y();
                    selectedPoint=i;
                    setMouseTracking(true);
                    return;
                }
            }
        }

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
        if(displayall==true)
        {
            points[selectedPoint]=event->pos();
            update();
            updateSignal();
        }
        else
        {
            points[selectedPoint].setX(event->x()-event_selected_dx);
            points[selectedPoint].setY(event->y()-event_selected_dy);
            update();
            updateSignal();
        }
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
    if(displayall==true){
        //画点
        pen.setColor(Qt::green);
        pen.setWidth(5);
        painter.setPen(pen);
        for(int i=0;i<24;i++)
        {
            if(pointSettled[i]==true){
                painter.drawPoint(points[i]);
            }

        }
        //画点标记
        pen.setColor(Qt::red);
        pen.setWidth(1);
        painter.setPen(pen);
        for(int i=0;i<24;i++)
        {
            if(pointSettled[i]==true){
                int x=points[i].x();
                int y=points[i].y();
                painter.drawText(QPoint(x+10,y),marks[i]);
            }
        }
        //画线
        if(line_display==true){
            pen.setColor(Qt::yellow);
            pen.setWidth(2);
            painter.setPen(pen);
            for(int i=0;i<13;i++)
            {
                if(pointSettled[lines[i][0]]&&pointSettled[lines[i][1]])//标准线
                {
                    painter.drawLine(points[lines[i][0]],points[lines[i][1]]);
                }
            }
        }
    }
    else
    {
        //画点
       /**/ pen.setColor(Qt::green);
        pen.setWidth(5);
        painter.setPen(pen);
        for(int i=0;i<24;i++)
        {
            if(pointActive[i]==true){
                painter.drawPoint(points[i]);
            }

        }
        //十字线
        /*pen.setColor(Qt::red);
        pen.setWidth(1);
        painter.setPen(pen);
        for(int i=0;i<24;i++)
        {
            if(pointActive[i]==true){
                int crosslength=10;
                QPoint center=points[i];
                QPoint up=QPoint(center.x(),center.y()-crosslength);
                QPoint down=QPoint(center.x(),center.y()+crosslength);
                QPoint left=QPoint(center.x()-crosslength,center.y());
                QPoint right=QPoint(center.x()+crosslength,center.y());

                painter.drawLine(up,down);
                painter.drawLine(left,right);
            }

        }*/
        //画点标记
        pen.setColor(Qt::red);
        pen.setWidth(1);
        painter.setPen(pen);
        for(int i=0;i<24;i++)
        {
            if(pointActive[i]==true){
                if(displayhalo==true)
                {
                    painter.drawEllipse(points[i],radius,radius);
                }
                int x=points[i].x();
                int y=points[i].y();
                painter.drawText(QPoint(x+10,y),marks[i]);
            }
        }
        //画线
        if(line_display==true){
            pen.setColor(Qt::yellow);
            pen.setWidth(2);
            painter.setPen(pen);
            for(int i=0;i<13;i++)
            {
                if(pointActive[lines[i][0]]&&pointActive[lines[i][1]])//标准线
                {
                    painter.drawLine(points[lines[i][0]],points[lines[i][1]]);
                }
            }
        }
    }




}




