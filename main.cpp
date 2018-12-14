#include "mainwindow.h"
#include <QApplication>
#include "watersurface.h"
#include "inkdrop.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InkDrop *inkDrop = new InkDrop(100, 1, 0, 0, 100, 100, 100, 2);
    WaterSurface waterSurface(inkDrop);
    waterSurface.startDrawing(5);
    waterSurface.show();
    return a.exec();
}
