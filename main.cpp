#include "mainwindow.h"
#include <QApplication>
#include "watersurface.h"
#include "inkdrop.h"
#include <QThread>
#include "showdetail.h"
#include <QTableWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InkDrop *inkDrop;
    WaterSurface *waterSurface = new WaterSurface();
    waterSurface->setInkDrop(inkDrop);

    ShowDetail *detailView = new ShowDetail();
    detailView->setInkDrop(inkDrop);

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setSurface(waterSurface);
    mainWindow->setDetailView(detailView);
    mainWindow->show();

    waterSurface->stopDrawing();
    return a.exec();
}
