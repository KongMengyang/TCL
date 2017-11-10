#include "mainwindow.h"
#include "logindlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginDlg login; //登陆界面
    if(login.exec()==QDialog::Accepted)
    {
        MainWindow w;
        w.show();

        return a.exec();
    }
    else
    {
        return 0;
    }
}
