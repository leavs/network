#ifndef WIFIDIALOG_H
#define WIFIDIALOG_H

#include <QDialog>

namespace Ui {
class wifidialog;
}

class wifidialog : public QDialog
{
    Q_OBJECT

public:
    explicit wifidialog(QWidget *parent = 0);
    ~wifidialog();

private slots:


    void on_pushButton_enable_clicked();

    void on_pushButton_disable_clicked();

    void on_pushButton_info_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::wifidialog *ui;
};

#endif // WIFIDIALOG_H
