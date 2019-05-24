#include "wifidialog.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wifidialog w;
    w.setWindowTitle("WIFI");
    w.show();

    QDesktopWidget *desktop = QApplication::desktop();
    w.move((desktop->width()-w.width())/2, (desktop->height()-w.height())/2);

    return a.exec();
}
