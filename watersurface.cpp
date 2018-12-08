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

void WaterSurface::setStartPos(int x, int y) {
    this->startPosX = translateX(x);
    this->startPosY = translateY(y);
}

void WaterSurface::setCheckRadius(int radius) {
    this->checkRadius = radius;
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

    inkDrop = new InkDrop(100 ,10, 0, 0);
    startTimer(5);
}
WaterSurface::WaterSurface(QWidget *parent)
    : QWidget(parent) {
}

// Chuyển từ tọa độ Đề Các sang tọa độ cửa sổ
// Hoành độ
int WaterSurface::translateX(int x) {
    return (x + getWidth()/2);
}
// Tung độ
int WaterSurface::translateY(int y) {
    return (-y + getHeight()/2);
}

void WaterSurface::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter qp(this);
    qp.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    fillBackground(&qp);
    drawCheckCircle(&qp);
    drawAxis(&qp);
    drawPoints(&qp);

}


// Tô màu nền cho mặt nước
void WaterSurface::fillBackground(QPainter *qp) {
    qp->fillRect(0, 0, width, height, QColor("#323133"));
}

// Vẽ vòng tròn xung quanh điểm bắt đầu
void WaterSurface::drawCheckCircle(QPainter *qp) {
    qp->setPen(QPen("#3c3b3d"));
    qp->setBrush(QBrush("#3c3b3d"));
    qp->drawEllipse(startPosX-checkRadius, startPosY-checkRadius, 2*checkRadius, 2*checkRadius);
}

void WaterSurface::drawAxis(QPainter *qp) {
    QPen pen(Qt::white, 0.5, Qt::SolidLine);
    qp->setPen(pen);
    qp->drawLine(width/2, 0, width/2, height);
    qp->drawLine(0, height/2, width, height/2);
}

void WaterSurface::drawPoints(QPainter *qp) {
    int n = inkDrop->getAmount();
    for (int i=0; i<n; i++) {
        qp->setPen(QPen("#ffffff"));
        qp->setBrush(QBrush("#ffffff"));
        qp->drawEllipse(translateX(inkDrop->getSingleDrop()[i].x)-1, translateY(inkDrop->getSingleDrop()[i].y)-1, 3, 3);
    }
}
void WaterSurface::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    inkDrop->update();
    repaint();
}
