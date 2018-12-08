#include "mainwindow.h"
#include <QApplication>
#include "watersurface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WaterSurface waterSurface(300, 400);
    waterSurface.setStartPos(0, 0);
    waterSurface.setCheckRadius(100);
    waterSurface.show();
    waterSurface.update();
    return a.exec();
}
