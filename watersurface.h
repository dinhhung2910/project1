#ifndef WATERSURFACE_H
#define WATERSURFACE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "inkdrop.h"
/**
 * @brief The WaterSurface class
 * implements lớp QWidget của Qt
 * @param width: chiều rộng mặt nước
 * @param height: chiều dọc mặt nước
 * @param startPosX, startPosY: Tọa độ thả giọt mực xuống
 * @param checkRadius: Bán kính cần kiểm tra quanh giọt mực
 * @param inkDrop: Con trỏ trỏ đến giọt mực
 *
 * @param delay: thời gian delay giữa các bước hiển thị
 * @param timerID: ID của bộ đếm thời gian
 */
class WaterSurface : public QWidget
{
private:
    int width, height, startPosX, startPosY, checkRadius;
    int delay, timerID;
    InkDrop* inkDrop;
public:

    WaterSurface(QWidget *parent = 0);
    /**
     * @brief Các phương thức khởi tạo WaterSurface
     * @param width: chiều rộng
     * @param height: chiều cao
     */
    WaterSurface(int width, int height);

    /**
     * @brief Các phương thức khởi tạo WaterSurface
     * @param inkDrop: giọt mực trên màn hình
     */
    WaterSurface(InkDrop* inkdrop);


    //Get and Set methods

    void setWidth (int width);
    void setHeight (int height);
    void setStartPos (int x, int y);
    void setCheckRadius (int radius);
    void setDelay (int delay);

    int getWidth ();
    int getHeight();
    int getDelay();

    // Đổi từ tọa độ Đề Các sang tọa độ cửa sổ
    int translateX(int x);
    int translateY(int y);

    // Tô màu nền
    void fillBackground(QPainter *qp);
    // Vẽ vòng tròn xuất phát
    void drawCheckCircle(QPainter *qp);
    // Vẽ trục tọa độ
    void drawAxis(QPainter *qp);
    // Vẽ các điểm
    void drawPoints(QPainter *qp);

    /**
     * @brief startDrawing bắt đầu việc vẽ hình
     * @param delay: thời gian delay giữa các khung hình
     */
    void startDrawing(int delay);

    /**
     * @brief stopTimer ngừng việc vẽ hình
     * @param timerID: id của bộ đếm thời gian
     */
    void stopDrawing();
protected:
    // Override paintEvent của QWidget
    // Hàm tự động được gọi
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *event);
};

#endif // WATERSURFACE_H
