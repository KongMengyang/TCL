#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openPushbutton_clicked()
{
    QString filename;
    filename=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("选择图像"),"",tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(!filename.isEmpty())
    {
        if(originimage.load(filename))//读取图像
        {
            initialWidth=originimage.width();
            initialHeight=originimage.height();
            currentWidth=initialWidth;
            currentHeight=initialHeight;

            ui->imageLabel->resize(QSize(initialWidth,initialHeight));
            currentimage=originimage;
            ui->imageLabel->setPixmap(QPixmap::fromImage(currentimage));


            ui->zoomSlider->setValue(100);
            ui->brightnessSlider->setValue(0);
            ui->contrastSlider->setValue(0);
            ui->imageLabel->index=0;
            ui->imageLabel->flag_start=false;
            //自适应大小
            for(int i=20;i<180;i=i+5)
            {
                if(initialWidth*i/100<ui->scrollArea->width()&&initialHeight*i/100<ui->scrollArea->height())
                {
                }
                else
                {

                    //qDebug()<<i;
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
        qDebug()<<"1";
        ui->scrollAreaWidgetContents->setFixedSize(currentWidth,currentHeight);
    }
    /*if(ui->scrollAreaWidgetContents->width()>currentWidth)
    {
        ui->scrollAreaWidgetContents->setFixedSize(currentWidth,currentHeight);
    }*/
    qDebug()<<ui->scrollArea->size()<<" "<<ui->scrollAreaWidgetContents->size()<<" "<<ui->imageLabel->size()<<" "<<ui->zoomSlider->value();



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

    for(int i=0;i<ui->imageLabel->index;i++)
    {
        int newx=orginpoints[i].x()*ui->zoomSlider->value()/100;
        int newy=orginpoints[i].y()*ui->zoomSlider->value()/100;
        ui->imageLabel->points[i].setX(newx);
        ui->imageLabel->points[i].setY(newy);
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

void MainWindow::on_clearPushbutton_clicked()
{
    ui->imageLabel->index=0;
    ui->imageLabel->flag_start=false;
    ui->imageLabel->update();
    for(int i=0;i<15;i++)
    {
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(""));
    }
}
