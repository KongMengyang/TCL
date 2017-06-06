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

#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QImage originimage;
    QImage currentimage;
    QString strdian;
    int initialWidth;
    int initialHeight;
    int currentWidth;
    int currentHeight;
    int rThreshold=127;
    int gThreshold=127;
    int bThreshold=127;
    QPoint orginpoints[24];
    double length_10mm=1;

    double angle_3points(QPoint a,QPoint b,QPoint c);
    double angle_2lines(QPoint a,QPoint b,QPoint c,QPoint d);
    double distance_pointtoline(QPoint a,QPoint b,QPoint c);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openPushbutton_clicked();

    void on_zoomSlider_valueChanged(int value);

    void on_brightnessSlider_valueChanged(int value);

    void on_contrastSlider_valueChanged(int value);

    void on_clearPushbutton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
