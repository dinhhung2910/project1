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
 */
class WaterSurface : public QWidget
{
private:
    int width, height, startPosX, startPosY, checkRadius;
    InkDrop* inkDrop;
public:
    WaterSurface(QWidget *parent = 0);
    WaterSurface(int width, int height);

    //Get and Set methods

    void setWidth (int width);
    void setHeight (int height);
    void setStartPos (int x, int y);
    void setCheckRadius (int radius);

    int getWidth ();
    int getHeight();

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
protected:
    // Override paintEvent của QWidget
    // Hàm tự động được gọi
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *event);
};

#endif // WATERSURFACE_H
