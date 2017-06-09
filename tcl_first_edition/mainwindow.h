#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QFrame>
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QColor>
#include <QIcon>
#include <QStringList>
#include <QString>
#include <QTextStream>
#include <math.h>
#include <QVector>
#include <QTableWidgetItem>

#include <opencv2/opencv.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
namespace Ui {
class MainWindow;
}

class tclObj
{

public:
    double max,min;
    int type;
    int points[4];
    tclObj(void)
    {
        max=0;
        min=0;
        type=0;
        points[4]={-1};
    }

    tclObj(double a,double b,int c,int p0,int p1,int p2,int p3)
    {

        max=a;
        min=b;
        type=c;
        points[0]=p0;
        points[1]=p1;
        points[2]=p2;
        points[3]=p3;

    }


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QImage originimage;
    QImage currentimage;
    double length_10mm=1;
    int initialWidth;
    int initialHeight;
    int currentWidth;
    int currentHeight;
    int rThreshold=127;
    int gThreshold=127;
    int bThreshold=127;
    bool pointSettled[24]={false};
    QPoint orginpoints[24];
    tclObj targetObj[15];

    double angle_3points(QPoint a,QPoint b,QPoint c);
    double angle_2lines(QPoint a,QPoint b,QPoint c,QPoint d);
    double distance_pointtoline(QPoint a,QPoint b,QPoint c);
    void showObjData(int x);
    void activePoint(int x);
    cv::Mat originmat;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
private slots:
    void on_openPushbutton_clicked();
    void on_zoomSlider_valueChanged(int value);
    void on_measurePushbutton_clicked();
    void on_brightnessSlider_valueChanged(int value);
    void on_contrastSlider_valueChanged(int value);
    void instructSlot(int index);
    void updateSlot();
    void on_clearPushbutton_clicked();
    void on_line_displayButton_clicked();
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_displayallButton_clicked();
    void on_displayhaloButton_clicked();

    void on_sharpenPushButton_clicked();

signals:
};




#endif // MAINWINDOW_H
