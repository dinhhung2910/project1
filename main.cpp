#include "mainwindow.h"
#include <QApplication>
#include "watersurface.h"
#include "inkdrop.h"
#include <QThread>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InkDrop *inkDrop;
    WaterSurface *waterSurface = new WaterSurface();
    waterSurface->setInkDrop(inkDrop);

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setSurface(waterSurface);
    mainWindow->show();


    waterSurface->stopDrawing();
    return a.exec();
}
