#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QTimer>
#include <QHeaderView>
#include <QAbstractItemModel>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Khởi tạo clock và gán công việc cho nó
    clock = new QTimer();
    connect(clock, SIGNAL(timeout()), this, SLOT(showCount()));

    isStarted=false;
}

MainWindow::~MainWindow()
{
    delete ui;
    try {
        surface->stopDrawing();
    } catch (int e) {

    }
}



void MainWindow::setSurface(WaterSurface* surface) {
    this->surface = surface;
    this->inkDrop = surface->getInkDrop();

    isStarted = false;
}

WaterSurface* MainWindow::getSurface() {
    return this->surface;
}


/**
 * @brief MainWindow::startDrawing
 *
 */
void MainWindow::startDrawing() {

    int amount = ui->numberOfDrop->displayText().toInt();
    int radius = ui->radius->displayText().toInt();
    int maxX = ui->width->displayText().toInt()/2;
    int maxY = ui->height->displayText().toInt()/2;
    int startX = ui->startX->displayText().toInt();
    int startY = ui->startY->displayText().toInt();
    float maxSpeed = ui->maxSpeed->displayText().toFloat();
    int mode = ui->selectMode->currentIndex()+1;

    timeCheck = ui->checkTimer->displayText().toInt();
    int errorCode = inkDrop->validate(amount, radius, startX, startY, maxX, maxY, maxSpeed);

    if (timeCheck <= 0)
        errorCode = 69;

    QString errorMessage;

    switch (errorCode) {
        case (1): errorMessage="Số lượng hạt phải lớn hơn 0"; break;
        case (2): errorMessage="Bán kính kiểm tra phải lớn hơn 0"; break;
        case (3): errorMessage="Chiều ngang phải lớn hơn 0"; break;
        case (4): errorMessage="Chiều dọc phải lớn hơn 0"; break;
        case (5): errorMessage="Hoành độ xuất phát không được vượt quá bề ngang"; break;
        case (6): errorMessage="Tung độ xuất phát không được vượt quá bề dọc"; break;
        case (7): errorMessage="Tốc độ phải lớn hơn 0"; break;
        case (69): errorMessage="Thời gian kiểm tra phải lớn hơn 0"; break;
    }

    if (errorCode) {
        QMessageBox Qmessage;
        Qmessage.setText(errorMessage);
        Qmessage.setStyleSheet("background-color: #374353; color: white; font-family: 'SF Pro Text';");
        Qmessage.setWindowTitle("Lỗi");
        Qmessage.show();
        Qmessage.exec();
    }
    else {
        inkDrop = new InkDrop(amount, 1, startX, startY, maxX, maxY, radius, maxSpeed, 10, mode);
        surface = new WaterSurface(inkDrop);

        isStarted = true;
        timer = 0;
        ui->checkResultSet->clear();

        surface->startDrawing(10);
        surface->show();

        clock->start(timeCheck);
    }
}

void MainWindow::showCount() {
    QTextStream out(stdout);
    //out << inkDrop->getCount();
    timer += timeCheck;

    QString output = "";

    QString time = QDateTime::fromMSecsSinceEpoch(timer).toUTC().toString("hh:mm:ss.zzz");

    output += QStringLiteral("%1: ").arg(time);
    output += QStringLiteral("%1").arg(inkDrop->getCount());
    output += "\n";
    ui->checkResultSet->insertPlainText(output);
    ui->checkResultSet->moveCursor(QTextCursor::End);
}

void MainWindow::resumeDrawing() {
    surface->startDrawing(10);
    surface->show();
    clock->start(timeCheck);
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_startDrawing_clicked()
{
    if (!isStarted) {
        startDrawing();
    }
    else resumeDrawing();

}

void MainWindow::on_pauseDrawing_clicked()
{
    if (isStarted) {
        surface->stopDrawing();
        clock->stop();
    }
}

void MainWindow::on_stopDrawing_clicked()
{
    if (isStarted) {
        isStarted = false;
        surface->stopDrawing();
        clock->stop();
        surface->close();

        delete inkDrop;
        delete surface;
    }
}
