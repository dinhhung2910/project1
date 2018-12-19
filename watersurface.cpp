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

void WaterSurface::setDelay(int delay) {
    this->delay = delay;
}

void WaterSurface::setCheckRadius(int radius) {
    this->checkRadius = radius;
}
void WaterSurface::setInkDrop(InkDrop* inkDrop) {
    this->inkDrop = inkDrop;
}

int WaterSurface::getWidth() {
    return this->width;
}
int WaterSurface::getHeight() {
    return this->height;
}
int WaterSurface::getDelay() {
    return this->delay;
}
InkDrop* WaterSurface::getInkDrop() {
    return this->inkDrop;
}

/**
 * @brief Các phương thức khởi tạo WaterSurface
 * @param width: chiều rộng
 * @param height: chiều cao
 */
WaterSurface::WaterSurface(int width, int height)
{
    setWidth(width);
    setHeight(height);
    this->setFixedSize(getWidth(), getHeight());

    startTimer(5);
}

/**
 * @brief Phương thức khỏi tạo mặc định
 */
WaterSurface::WaterSurface(QWidget *parent)
    : QWidget(parent) {
}

/**
 * @brief Các phương thức khởi tạo WaterSurface
 * @param inkDrop: giọt mực trên màn hình
 */
WaterSurface::WaterSurface(InkDrop* inkDrop) {
    this->inkDrop = inkDrop;
    setWidth(2*inkDrop->getMaxX());
    setHeight(2*inkDrop->getMaxY());
    this->setFixedSize(getWidth(), getHeight());
    setStartPos(inkDrop->getStartX(), inkDrop->getStartY());
    setCheckRadius(inkDrop->getRadius());
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
    qp->fillRect(0, 0, width, height, QColor("#374353"));
}

// Vẽ vòng tròn xung quanh điểm bắt đầu
void WaterSurface::drawCheckCircle(QPainter *qp) {
    qp->setPen(QPen("#25bea0"));
    qp->setBrush(QBrush("#25bea0"));
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

void WaterSurface::startDrawing(int delay) {

    // Dừng bộ đếm thời gian cũ, nếu có
    stopDrawing();

    // Bắt đầu bộ đếm thời gian mới với delay mới
    this->timerID = startTimer(delay);
}

void WaterSurface::stopDrawing() {
    // Dừng bộ đếm thời gian cũ, nếu có
    try {
        killTimer(this->timerID);
    } catch (int e) {
    }
}
