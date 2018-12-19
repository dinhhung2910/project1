#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "watersurface.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(WaterSurface* surface);
    ~MainWindow();

    void setSurface(WaterSurface* surface);
    WaterSurface* getSurface();

private slots:
    void on_pushButton_clicked();

    void on_startDrawing_clicked();

    void on_pauseDrawing_clicked();

    void showCount();

/***
 * @param isStarted trạng thái cửa sổ: đã được khởi tạo hay chưa
 * @param frameSpeed Bao nhiêu ms thì cập nhật khung hình 1 lần
 *
*/
    void on_stopDrawing_clicked();

private:
    Ui::MainWindow *ui;
    InkDrop* inkDrop;
    WaterSurface* surface;


    bool isStarted; // Việc vẽ đã được bắt đầu hay chưa
    int frameSpeed; // Tốc độ khung hình
    long timer;     // Đo thời gian chương trình đã chạy
    int timeCheck;  // Khoảng cách thời gian giữa các lần kiểm tra

    QTimer* clock; // Đối tượng QTimer để thực hiện một công việc lặp đi lặp lại, ở đây là đếm số hạt mực nằm trong bán kính r
    /**
     * @brief startDrawing Bắt đầu vẽ
     */
    void startDrawing();
    void resumeDrawing();


};

#endif // MAINWINDOW_H
