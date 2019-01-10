#include "wifidialog.h"
#include "ui_wifidialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

wifidialog::wifidialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wifidialog)
{
    ui->setupUi(this);
}

wifidialog::~wifidialog()
{
    delete ui;
}

void wifidialog::on_pushButton_enable_clicked()
{
    this->ui->textBrowser->setText(" ");
    system("ifconfig wlan0 up");
    system("wifienable.sh");
    this->ui->textBrowser->setText("WIFI Enabled!");
}

void wifidialog::on_pushButton_disable_clicked()
{
    this->ui->textBrowser->setText(" ");
    system("ifconfig wlan0 down");
    this->ui->textBrowser->setText("WIFI Disabled!");
}

void wifidialog::on_pushButton_info_clicked()
{
    this->ui->textBrowser->setText("");
    system("ifconfig > /usr/ifconfig.txt");
    QString filepath="/usr/ifconfig.txt";
    QFile file(filepath);
    if (file.open(QIODevice::ReadWrite|QIODevice::Text)){
        QTextStream in(&file);
        QString line = in.readAll();
        this->ui->textBrowser->setText(line);
    }
    else
    {
        QMessageBox::critical(this,"Error","Open config file error!!");
    }

    file.close();
}

void wifidialog::on_pushButton_close_clicked()
{
    system("rm /usr/ifconfig.txt");
    this->close();
}
