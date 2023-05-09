#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

   /* QFile qssFile("./qss/navigationBar.css");
    if (qssFile.open(QFile::ReadOnly)) {
        a.setStyleSheet(qssFile.readAll());
    }
    qssFile.close();*/

    MainWindow w;
    w.show();
    return QApplication::exec();
}
