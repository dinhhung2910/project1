#include "mainwindow.h"
#include <QApplication>
#include "watersurface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WaterSurface waterSurface(300, 400);
    waterSurface.show();

    return a.exec();
}
