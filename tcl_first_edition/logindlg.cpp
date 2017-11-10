#include "logindlg.h"
#include "ui_logindlg.h"
#include  <QMessageBox>

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/image/icon/iMQ.ico"));
    this->setWindowTitle("登录");
}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_okPushButton_clicked()
{
    if(this->ui->usernameText->text().trimmed()== tr("admin") &&
         this->ui->pswText->text()==tr("123456"))
      {
          accept();
      }
      else
      {
          //QTextCodec::setCodecForTr( QTextCodec::codecForName("GBK") );
          QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误!"),QMessageBox::Yes);
          this->ui->usernameText->clear();
          this->ui->pswText->clear();
          this->ui->usernameText->setFocus();
      }
}

void loginDlg::on_cancelPushButton_clicked()
{
    this->close();
}
