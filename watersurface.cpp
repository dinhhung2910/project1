#include "watersurface.h"
#include <QPainter>

// Get and Set methods
void WaterSurface::setWidth(int width) {
    if (width > 0)
        this->width = width;
}
void WaterSurface::setHeight(int height) {
    if (height > 0)
        this->height = height;
}
int WaterSurface::getWidth() {
    return this->width;
}
int WaterSurface::getHeight() {
    return this->height;
}

// Các phương thức khởi tạo
// Khởi tạo cửa sổ với 2 tham số chiều rộng và chiều cao
WaterSurface::WaterSurface(int width, int height)
{
    setWidth(width);
    setHeight(height);
    this->setFixedSize(getWidth(), getHeight());
}
WaterSurface::WaterSurface(QWidget *parent)
    : QWidget(parent) {
}

void WaterSurface::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter qp(this);
    fillBackground(&qp);
}


// Tô màu nền cho mặt nước
void WaterSurface::fillBackground(QPainter *qp) {
    QPen pen(Qt::black, 2, Qt::SolidLine);
    qp->setPen(pen);
    qp->drawLine(20, 40, 250, 40);
}
