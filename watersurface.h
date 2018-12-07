#ifndef WATERSURFACE_H
#define WATERSURFACE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

/**
 * @brief The WaterSurface class
 * implements lớp QWidget của Qt
 * @param width: chiều rộng mặt nước
 * @param height: chiều dọc mặt nước
 */
class WaterSurface : public QWidget
{
private:
    int width, height;
public:
    WaterSurface(QWidget *parent = 0);
    WaterSurface(int width, int height);

    //Get and Set methods

    void setWidth (int width);
    void setHeight (int height);
    int getWidth ();
    int getHeight();

    void fillBackground(QPainter *qp);
protected:
    // Override paintEvent của QWidget
    // Hàm tự động được gọi
    void paintEvent(QPaintEvent *e);
};

#endif // WATERSURFACE_H
