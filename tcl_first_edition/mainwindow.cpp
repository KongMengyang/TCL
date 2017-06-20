#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString strdian=ui->instructLabel->text();
    ui->instructLabel->setText("");

    this->setWindowIcon(QIcon(":/images/image/icon/iMQ.ico"));
    this->setWindowTitle("投影测量");
    ui->scrollAreaWidgetContents->setFixedSize(ui->scrollArea->width()-2,ui->scrollArea->height()-2);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QObject::connect(ui->imageLabel,SIGNAL(instructSignal(int)),this,SLOT(instructSlot(int)));
    QObject::connect(ui->imageLabel,SIGNAL(updateSignal()),this,SLOT(updateSlot()));
    //初始化测量项目
    targetObj[0]=tclObj(86.8,68.8,0,2,3,4,-1);//SNA
    targetObj[1]=tclObj(84.0,76.2,0,2,3,5,-1);//SNB
    targetObj[2]=tclObj(4.7,0.7,0,4,3,5,-1);//ANB
    targetObj[3]=tclObj(89.1,81.7,1,3,8,6,7);//NP-FH面角
    targetObj[4]=tclObj(73.4,59.2,1,2,9,7,6);//Y轴角
    targetObj[5]=tclObj(36.7,25.5,1,11,10,7,6);//MP-FH下颌平面角
    targetObj[6]=tclObj(10.4,1.6,1,3,4,8,4);//NP-PA颌凸角
    targetObj[7]=tclObj(112.0,99.4,1,12,13,3,2);//上1-SN角
    targetObj[8]=tclObj(7.5,2.7,2,12,3,4,-1);//上1-NA距
    targetObj[9]=tclObj(28.5,17.1,1,3,4,12,13);//上1-NA角
    targetObj[10]=tclObj(100.1,87.7,1,14,15,10,11);//下1-MP角
    targetObj[11]=tclObj(8.8,4.6,2,14,3,5,-1);//下1-NB距
    targetObj[12]=tclObj(36.1,24.5,1,14,15,5,3);//下1-NB角
    targetObj[13]=tclObj(132.4,116.0,1,14,15,13,12);//上1-下1角
    targetObj[14]=tclObj(110,80,0,16,17,18,-1);//NLA角
    //模板角
    orginpoints[0]=QPoint(1984,513);
    orginpoints[1]=QPoint(1984,591);
    orginpoints[2]=QPoint(1284,846);
    orginpoints[3]=QPoint(1771,828);
    orginpoints[4]=QPoint(1721,1280);
    orginpoints[5]=QPoint(1643,1516);
    orginpoints[6]=QPoint(1097,960);
    orginpoints[7]=QPoint(1684,1024);
    orginpoints[8]=QPoint(1646,1614);
    orginpoints[9]=QPoint(1622,1644);
    orginpoints[10]=QPoint(1568,1633);
    orginpoints[11]=QPoint(1173,1402);
    orginpoints[12]=QPoint(1742,1388);
    orginpoints[13]=QPoint(1673,1253);
    orginpoints[14]=QPoint(1720,1397);
    orginpoints[15]=QPoint(1637,1500);
    orginpoints[16]=QPoint(1908,1213);
    orginpoints[17]=QPoint(1837,1248);
    orginpoints[18]=QPoint(1835,1347);
    /*
    activePoint(0);
    activePoint(1);
    ui->imageLabel->pointActive[0]=false;
    ui->imageLabel->pointActive[1]=false;*/
}


MainWindow::~MainWindow()
{
    delete ui;
}

string qstr2str(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return string(cdata);
}

void MainWindow::on_openPushbutton_clicked()
{
    QString filename;
    filename=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("选择图像"),"",tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(!filename.isEmpty())
    {
        if(originimage.load(filename))//读取图像
        {
            originimage_backup=originimage;
            string str=qstr2str(filename);
            originmat=cv::imread(str);
            //QImageToMat();
            cout<<str<<endl;
            qDebug()<<filename;
            initialWidth=originimage.width();
            initialHeight=originimage.height();
            currentWidth=initialWidth;
            currentHeight=initialHeight;

            ui->imageLabel->setFixedSize(QSize(initialWidth,initialHeight));
            currentimage=originimage;


            ui->imageLabel->setPixmap(QPixmap::fromImage(currentimage));

            ui->zoomSlider->setValue(100);
            ui->brightnessSlider->setValue(0);
            ui->contrastSlider->setValue(0);
            //ui->instructimgLabel->setPixmap(NULL);
            on_clearPushbutton_clicked();
            //自适应大小
            qDebug()<<"123123";
            for(int i=20;i<180;i=i+5)
            {
                if(initialWidth*i/100<ui->scrollArea->width()&&initialHeight*i/100<ui->scrollArea->height())
                {
                }
                else
                {

                    qDebug()<<i;
                    ui->zoomSlider->setValue(i-5);
                    break;
                }

            }

        }
        else
        {
            QMessageBox::information(this,QString::fromLocal8Bit("打开图像失败"),QString::fromLocal8Bit("打开图像失败!"));

            return;
        }
    }
    else
    {
        return;
    }
}

void MainWindow::on_measurePushbutton_clicked()
{
    if(originimage.isNull())
    {
        QMessageBox::information(this,QString("请先导入图像"),QString("请先导入图像!"));
        return;
    }
    if(ui->imageLabel->flag_start==true)
    {
        QMessageBox::information(this,QString("请先清空选点"),QString("请先清空选点!"));
        return;
    }
    ui->imageLabel->flag_start=true;
    ui->imageLabel->displayall=true;
    ui->imageLabel->flag_flow=true;
    ui->imageLabel->setCursor(Qt::CrossCursor);
    instructSlot(0);
}

void MainWindow::on_zoomSlider_valueChanged(int value)
{
    currentWidth=initialWidth*value/100;
    currentHeight=initialHeight*value/100;
    QImage newImage=originimage.scaled(currentWidth,currentHeight);
    ui->imageLabel->setFixedSize(QSize(currentWidth,currentHeight));
    //ui->imageLabel->setScaledContents(false);
    int blank=2;
    if(ui->scrollArea->width()-blank>=currentWidth&&ui->scrollArea->height()-blank>=currentHeight)
    {
        ui->scrollAreaWidgetContents->setFixedSize(ui->scrollArea->width()-blank,ui->scrollArea->height()-blank);
    }
    else if(ui->scrollArea->width()-blank>=currentWidth&&ui->scrollArea->height()-blank<=currentHeight)
    {
        ui->scrollAreaWidgetContents->setFixedSize(ui->scrollArea->width()-blank,currentHeight);
    }
    else if(ui->scrollArea->width()-blank<=currentWidth&&ui->scrollArea->height()-blank>=currentHeight)
    {
        ui->scrollAreaWidgetContents->setFixedSize(currentWidth,ui->scrollArea->height()-blank);
    }
    else
    {
        //qDebug()<<"1";
        ui->scrollAreaWidgetContents->setFixedSize(currentWidth,currentHeight);
    }

    //qDebug()<<ui->scrollArea->size()<<" "<<ui->scrollAreaWidgetContents->size()<<" "<<ui->imageLabel->size()<<" "<<ui->zoomSlider->value();


    /**/
    QColor oldColor;
    int r=0,g=0,b=0;
    int delta;
    delta=ui->contrastSlider->value();
    for(int y=0; y<newImage.height(); y++)
    {
        for(int x=0; x<newImage.width(); x++)
        {
            oldColor = QColor(newImage.pixel(x,y));

            r=rThreshold+(oldColor.red()-rThreshold)*(100+delta)/100;
            if(r>255){r=255;}else if(r<0){r=0;}

            g=gThreshold+(oldColor.green()-gThreshold)*(100+delta)/100;
            if(g>255){g=255;}else if(g<0){g=0;}

            b=bThreshold+(oldColor.blue()-bThreshold)*(100+delta)/100;
            if(b>255){b=255;}else if(b<0){b=0;}

            newImage.setPixel(x,y, qRgb(r,g,b));
        }
    }

    delta = ui->brightnessSlider->value();
    for(int y=0; y<newImage.height(); y++)
    {
        for(int x=0; x<newImage.width(); x++)
        {
            oldColor = QColor(newImage.pixel(x,y));
            r = oldColor.red() + delta;
            if(r>255){r=255;}else if(r<0){r=0;}

            g = oldColor.green() + delta;
            if(g>255){g=255;}else if(g<0){g=0;}

            b = oldColor.blue() + delta;
            if(b>255){b=255;}else if(b<0){b=0;}

            newImage.setPixel(x,y, qRgb(r,g,b));
        }
    }


    ui->imageLabel->setPixmap(QPixmap::fromImage(newImage));

    for(int i=0;i<24;i++)
    {
        if(pointSettled[i]==true)
        {

            int newx=orginpoints[i].x()*ui->zoomSlider->value()/100;
            int newy=orginpoints[i].y()*ui->zoomSlider->value()/100;
            ui->imageLabel->points[i].setX(newx);
            ui->imageLabel->points[i].setY(newy);
        }
        //qDebug()<<ui->imageLabel->points[i]<<" "<<ui->zoomSlider->value();
    }/**/

    ui->imageLabel->update();


}

void MainWindow::on_brightnessSlider_valueChanged(int value)
{

    QColor oldColor;
    int r=0,g=0,b=0;
    QImage newImage = originimage;
    int delta;
    newImage=originimage.scaled(currentWidth,currentHeight);
    delta=ui->contrastSlider->value();
    for(int y=0; y<newImage.height(); y++)
    {
        for(int x=0; x<newImage.width(); x++)
        {
            oldColor = QColor(newImage.pixel(x,y));

            r=rThreshold+(oldColor.red()-rThreshold)*(100+delta)/100;
            if(r>255){r=255;}else if(r<0){r=0;}

            g=gThreshold+(oldColor.green()-gThreshold)*(100+delta)/100;
            if(g>255){g=255;}else if(g<0){g=0;}

            b=bThreshold+(oldColor.blue()-bThreshold)*(100+delta)/100;
            if(b>255){b=255;}else if(b<0){b=0;}

            newImage.setPixel(x,y, qRgb(r,g,b));
        }
    }

    delta = value;
    for(int y=0; y<newImage.height(); y++)
    {
        for(int x=0; x<newImage.width(); x++)
        {
            oldColor = QColor(newImage.pixel(x,y));
            r = oldColor.red() + delta;
            if(r>255){r=255;}else if(r<0){r=0;}

            g = oldColor.green() + delta;
            if(g>255){g=255;}else if(g<0){g=0;}

            b = oldColor.blue() + delta;
            if(b>255){b=255;}else if(b<0){b=0;}

            newImage.setPixel(x,y, qRgb(r,g,b));
        }
    }


    //currentimage=newImage;

    ui->imageLabel->setPixmap(QPixmap::fromImage(newImage));

}

void MainWindow::on_contrastSlider_valueChanged(int value)
{

    QColor oldColor;
    int delta=value;
    int r=0,g=0,b=0;
    QImage newImage = originimage;
    newImage=originimage.scaled(currentWidth,currentHeight);
    for(int y=0; y<newImage.height(); y++)
    {
        for(int x=0; x<newImage.width(); x++)
        {
            oldColor = QColor(newImage.pixel(x,y));

            r=rThreshold+(oldColor.red()-rThreshold)*(100+delta)/100;
            if(r>255){r=255;}else if(r<0){r=0;}

            g=gThreshold+(oldColor.green()-gThreshold)*(100+delta)/100;
            if(g>255){g=255;}else if(g<0){g=0;}

            b=bThreshold+(oldColor.blue()-bThreshold)*(100+delta)/100;
            if(b>255){b=255;}else if(b<0){b=0;}

            newImage.setPixel(x,y, qRgb(r,g,b));
        }
    }

    delta=ui->brightnessSlider->value();
    for(int y=0; y<newImage.height(); y++)
    {
        for(int x=0; x<newImage.width(); x++)
        {
            oldColor = QColor(newImage.pixel(x,y));
            r = oldColor.red() + delta;
            if(r>255){r=255;}else if(r<0){r=0;}

            g = oldColor.green() + delta;
            if(g>255){g=255;}else if(g<0){g=0;}

            b = oldColor.blue() + delta;
            if(b>255){b=255;}else if(b<0){b=0;}

            newImage.setPixel(x,y, qRgb(r,g,b));
        }
    }

    //currentimage=newImage;
    newImage=newImage.scaled(currentWidth,currentHeight);
    ui->imageLabel->setPixmap(QPixmap::fromImage(newImage));
}

double MainWindow::angle_3points(QPoint a,QPoint b,QPoint c)
{
    double result;
    double x1=a.x()-b.x();
    double x2=c.x()-b.x();
    double y1=a.y()-b.y();
    double y2=c.y()-b.y();
    double cosvalue=(x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2));
    result=acos(cosvalue)/3.1415*180;
    return result;
}

double MainWindow::angle_2lines(QPoint a,QPoint b,QPoint c,QPoint d)
{
    double result;
    double x1=a.x()-b.x();
    double x2=d.x()-c.x();
    double y1=a.y()-b.y();
    double y2=d.y()-c.y();
    double cosvalue=(x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2));
    result=acos(cosvalue)/3.1415*180;
    return result;
}

double MainWindow::distance_pointtoline(QPoint a, QPoint b, QPoint c)
{
    double result;
    if(b.x()==c.x())
    {
        result=a.x()-b.x();
    }
    else if(b.y()==c.y())
    {
        result=a.y()-b.y();
    }
    else
    {
        double k=(b.y()-c.y())/(b.x()-c.x());
        double bb=b.y()-k*b.x();
        result=(a.y()-k*a.x()-bb)/sqrt(1.0+k*k);
    }
    if(result<0)
    {
        result=-result;
    }
    result=result*10/length_10mm;
    return result;

}


void MainWindow::instructSlot(int index)
{

    if(index>0){
        pointSettled[index-1]=true;
        orginpoints[index-1].setX(ui->imageLabel->points[index-1].x()*100/ui->zoomSlider->value());
        orginpoints[index-1].setY(ui->imageLabel->points[index-1].y()*100/ui->zoomSlider->value());
        updateSlot();
    }

    if(index==24)
    {
        for(int i=0;i<24;i++){
            qDebug()<<orginpoints[i];
            qDebug()<<double(orginpoints[i].x()/initialWidth)<<" "<<double(orginpoints[i].y()/initialWidth);
        }
        ui->imageLabel->setCursor(Qt::ArrowCursor);
    }




    //指令图
    QString filepath=":/images/image/instructimage/"+QString::number(index+1)+".png";
    QImage img=QImage(filepath);
    ui->instructimgLabel->setScaledContents(true);
    ui->instructimgLabel->setPixmap(QPixmap::fromImage(img));
    //指令
    QFile file(":/text/text/points.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;
    QTextStream in(&file);
    for(int i=0;i<index;i++)
        in.readLine();
    QString instructstr=in.readLine();
    //qDebug()<<instructstr;
    ui->instructLabel->setText(instructstr);
}

void MainWindow::showObjData(int x)
{
    tclObj obj=targetObj[x];
    if(obj.type==0)
    {
        if(pointSettled[obj.points[0]]&&pointSettled[obj.points[1]]&&pointSettled[obj.points[2]])//SNA角
        {
            double result=angle_3points(orginpoints[obj.points[0]],orginpoints[obj.points[1]],orginpoints[obj.points[2]]);
            QString strResult=QString::number(result, 10, 1);
            strResult+="°";
            int row=x;
            QTableWidgetItem *newitem=new QTableWidgetItem(strResult);
            newitem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(row,2,newitem);
            double min=obj.min;
            double max=obj.max;
            if(result<min)
            {
                ui->tableWidget->setItem(row,3,new QTableWidgetItem("偏低"));
                ui->tableWidget->item(row,3)->setTextColor(QColor(0, 0, 255));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
            else if(result>max)
            {

                ui->tableWidget->setItem(row,3,new QTableWidgetItem("偏高"));
                ui->tableWidget->item(row,3)->setTextColor(QColor(255, 0, 0));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
            else
            {
                ui->tableWidget->setItem(row,3,new QTableWidgetItem("正常"));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    else if(obj.type==1)
    {
        if(pointSettled[obj.points[0]]&&pointSettled[obj.points[1]]&&pointSettled[obj.points[2]]&&pointSettled[obj.points[3]])//NP-FH面角
        {
            double result=angle_2lines(orginpoints[obj.points[0]],orginpoints[obj.points[1]],orginpoints[obj.points[2]],orginpoints[obj.points[3]]);
            QString strResult=QString::number(result, 10, 1);
            strResult+="°";
            int row=x;
            QTableWidgetItem *newitem=new QTableWidgetItem(strResult);
            newitem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(row,2,newitem);
            double min=obj.min;
            double max=obj.max;
            if(result<min)
            {
                ui->tableWidget->setItem(row,3,new QTableWidgetItem("偏低"));
                ui->tableWidget->item(row,3)->setTextColor(QColor(0, 0, 255));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
            else if(result>max)
            {

                ui->tableWidget->setItem(row,3,new QTableWidgetItem("偏高"));
                ui->tableWidget->item(row,3)->setTextColor(QColor(255, 0, 0));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
            else
            {
                ui->tableWidget->setItem(row,3,new QTableWidgetItem("正常"));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
    else if(obj.type==2)
    {
        if(pointSettled[obj.points[0]]&&pointSettled[obj.points[1]]&&pointSettled[obj.points[2]])//上1-NA距
        {
            int row=x;
            double min=obj.min;
            double max=obj.max;
            double result=distance_pointtoline(orginpoints[obj.points[0]],orginpoints[obj.points[1]],orginpoints[obj.points[2]]);
            QString strResult=QString::number(result, 10, 1);
            strResult+="mm";
            QTableWidgetItem *newitem=new QTableWidgetItem(strResult);
            newitem->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(row,2,newitem);
            if(result<min)
            {
                ui->tableWidget->setItem(row,3,new QTableWidgetItem("偏低"));
                ui->tableWidget->item(row,3)->setTextColor(QColor(0, 0, 255));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
            else if(result>max)
            {

                ui->tableWidget->setItem(row,3,new QTableWidgetItem("偏高"));
                ui->tableWidget->item(row,3)->setTextColor(QColor(255, 0, 0));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
            else
            {
                ui->tableWidget->setItem(row,3,new QTableWidgetItem("正常"));
                ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}





void MainWindow::updateSlot()
{
    //int index=ui->imageLabel->index;
    orginpoints[ui->imageLabel->selectedPoint].setX(ui->imageLabel->points[ui->imageLabel->selectedPoint].x()*initialWidth/currentWidth);
    orginpoints[ui->imageLabel->selectedPoint].setY(ui->imageLabel->points[ui->imageLabel->selectedPoint].y()*initialHeight/currentHeight);

    if(pointSettled[0]&&pointSettled[1])//比例尺
    {
        int x=orginpoints[0].x()-orginpoints[1].x();
        int y=orginpoints[0].y()-orginpoints[1].y();
        length_10mm=sqrt(double(x*x+y*y));
    }
    for(int i=0;i<15;i++)
    {
        showObjData(i);

    }


}





void MainWindow::on_clearPushbutton_clicked()
{
    ui->imageLabel->index=0;
    ui->imageLabel->flag_start=false;
    ui->imageLabel->displayall=true;
    for(int i=0;i<24;i++)
    {
        pointSettled[i]=false;
        ui->imageLabel->pointSettled[i]=false;
        ui->imageLabel->pointActive[i]=false;
    }
    for(int i=0;i<15;i++)
    {
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(""));
    }
    ui->imageLabel->update();

}



void MainWindow::on_line_displayButton_clicked()
{
    if(ui->imageLabel->line_display==true)
    {
        ui->imageLabel->line_display=false;
    }
    else
    {
        ui->imageLabel->line_display=true;
    }
    ui->imageLabel->update();
}


void MainWindow::activePoint(int tarpoint){
    pointSettled[tarpoint]=true;
    ui->imageLabel->pointSettled[tarpoint]=true;
    ui->imageLabel->pointActive[tarpoint]=true;
    ui->imageLabel->points[tarpoint].setX(orginpoints[tarpoint].x()*ui->zoomSlider->value()/100);
    ui->imageLabel->points[tarpoint].setY(orginpoints[tarpoint].y()*ui->zoomSlider->value()/100);
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{

    if(originimage.isNull())
    {
        QMessageBox::information(this,QString("请先导入图像"),QString("请先导入图像!"));
        return;
    }
    if(item->column()!=0){
        return;
    }
    int x=item->row();
    tclObj tar=targetObj[x];


    activePoint(0);
    activePoint(1);
    for(int i=0;i<24;i++)
    {
        ui->imageLabel->pointActive[i]=false;
    }

    QString filepath=":/images/image/examples/example"+QString::number(x)+".jpg";
    QImage img=QImage(filepath);

    //qDebug()<<filepath;
    //qDebug()<<img.isNull();
    ui->instructimgLabel->setScaledContents(true);
    ui->instructimgLabel->setPixmap(QPixmap::fromImage(img));

    ui->instructLabel->setText("");
    ui->imageLabel->setCursor(Qt::ArrowCursor);
    ui->imageLabel->flag_start=true;
    ui->imageLabel->displayall=false;
    ui->imageLabel->flag_flow=false;
    ui->imageLabel->line_display=false;
    if(tar.type==0)
    {
        for(int i=0;i<3;i++){
            int tarpoint=tar.points[i];
            activePoint(tarpoint);

        }
    }
    else if(tar.type==1)
    {
        for(int i=0;i<4;i++){
            int tarpoint=tar.points[i];
            activePoint(tarpoint);

        }
    }
    else if(tar.type==2)
    {

        activePoint(0);
        activePoint(1);
        for(int i=0;i<3;i++){
            int tarpoint=tar.points[i];
            activePoint(tarpoint);

        }
    }
    else
    {

    }
    ui->imageLabel->update();
    updateSlot();

}

void MainWindow::on_displayallButton_clicked()
{
    if(ui->imageLabel->displayall==true)
    {
        ui->imageLabel->displayall=false;
    }
    else
    {
        ui->imageLabel->displayall=true;
    }
    ui->imageLabel->update();
}

void MainWindow::on_displayhaloButton_clicked()
{
    if(ui->imageLabel->displayhalo==true)
    {
        ui->imageLabel->displayhalo=false;
    }
    else
    {
        ui->imageLabel->displayhalo=true;
    }
    ui->imageLabel->update();
}

//Mat->QImage
QImage MatToQImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
void MainWindow::QImageToMat()
{
    cv::Mat mat;
    QImage image=originimage;
    switch (image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    originmat=mat;
}




void MainWindow::on_sharpenPushButton_clicked()
{
    if(flag_sharpened==false){

        /*
        //方法1
        cv::Mat sharpenedMat;
        cv::Mat kernel(3,3,CV_32F,cv::Scalar(-1));
        kernel.at<float>(1,1) = 8.9;
        cv::filter2D(originmat, sharpenedMat, originmat.depth(), kernel);*/


        //方法2
        cv::Mat imgSrc=originmat;
        cv::Mat imgBlurred;
        cv::Mat imgDst;
        cv::Mat lowContrastMask;
        double sigma = 3;
        int threshold = 0;
        float amount = 1;

        cv::GaussianBlur(imgSrc, imgBlurred, cv::Size(), sigma, sigma);
        lowContrastMask = abs(imgSrc-imgBlurred)<threshold;
        imgDst = imgSrc*(1+amount)+imgBlurred*(-amount);
        imgSrc.copyTo(imgDst, lowContrastMask);
        qDebug()<<"111";


        originimage=MatToQImage(imgDst);
        flag_sharpened=true;
    }
    else
    {
        originimage=originimage_backup;
        flag_sharpened=false;
    }

    int zoomValue=ui->zoomSlider->value();
    ui->zoomSlider->setValue(23);
    ui->zoomSlider->setValue(zoomValue);

}
