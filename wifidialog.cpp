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
    this->ui->pushButton_enable->setText("WIFI Enable");
    this->ui->pushButton_disable->setText("WIFI Disable");
}

wifidialog::~wifidialog()
{
    delete ui;
}

void wifidialog::on_pushButton_enable_clicked()
{
    this->ui->textBrowser->setText(" ");
    //system("ifconfig wlan0 up");
    //system("wifienable.sh");
    popen("ifconfig wlan0 up","r");
    popen("wifienable.sh","r");
    this->ui->textBrowser->setText("WIFI will be open in background, press \"Network Info\" to check\n\n\n\n*NOTE:\nUsing follow command to config YOURS wifi ssid and password first\n\n#wpa_passphrase \"wifi_ssid\" \"wifi_password\" >> /etc/wpa_supplicant.conf\n\nExample:\nctrl_interface=/var/run/wpa_supplicant\nctrl_interface_group=0\nctrl_interface_group=0\nnetwork={\n        ssid=\"wifi_ssid\"\n        #psk=\"wifi_password\"\n        psk=0fbbe9e700815707d38305d89e3260f3b2334d0a0979c61be8eeea6ca9b0cd64\n}");
    this->ui->pushButton_info->setText("Network Info");
}

void wifidialog::on_pushButton_disable_clicked()
{
    this->ui->textBrowser->setText(" ");
    system("ifconfig wlan0 down");
    this->ui->textBrowser->setText("WIFI Disabled!");
    this->ui->pushButton_info->setText("Network Info");
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
    this->ui->pushButton_info->setText("Refresh");
}

void wifidialog::on_pushButton_close_clicked()
{
    system("rm /usr/ifconfig.txt");
    this->close();
}
