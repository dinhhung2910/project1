#include "inkdrop.h"
#include "random.h"
#include "math.h"
#include "singledrop.h"
#include <QTextStream>

// get and set methods
void InkDrop::setAmount(int amount) {
    this->amount = amount;
}
void InkDrop::setFreq(int freq) {
    this->freq = freq;
}
void InkDrop::setStart(int startX, int startY) {
    this->startX = startX;
    this->startY = startY;
}

int InkDrop::getAmount() {
    return this->amount;
}
int InkDrop::getStartX() {
    return this->startX;
}
int InkDrop::getStartY() {
    return this->startY;
}
SingleDrop* InkDrop::getSingleDrop() {
    return this->single;
}
void InkDrop::setMax(int maxX, int maxY) {
    this->maxX = maxX;
    this->maxY = maxY;
}
int InkDrop::getMaxX() {
    return maxX;
}
int InkDrop::getMaxY() {
    return maxY;
}
void InkDrop::setMode(char mode) {
    this->mode = mode;
}
int InkDrop::getMode() {
    return mode;
}
void InkDrop::setRadius(int radius) {
    this->radius = radius;
}
int InkDrop::getRadius() {
    return this->radius;
}
void InkDrop::setMaxSpeed(float maxSpeed) {
    this->maxSpeed = maxSpeed;
}
float InkDrop::getMaxSpeed() {
    return this->maxSpeed;
}
void InkDrop::setDelay(int delay) {
    this->delay = delay;
}
int InkDrop::getDelay() {
    return this->delay;
}


InkDrop::InkDrop()
{}

InkDrop::InkDrop(int amount, int freq, int startX, int startY, int maxX, int maxY, int radius, float maxSpeed, int delay, int mode) {
    setAmount(amount);
    setFreq(freq);
    setStart(startX, startY);
    setRadius(radius);


    setMode(mode);
    setMax(maxX, maxY);


    setMaxSpeed(maxSpeed);
    setDelay(delay);

    single = new SingleDrop[amount];
    initSingle();
}

void InkDrop::initSingle() {
    for (int i=0; i<amount; i++) {
        single[i].x = startX;
        single[i].y = startY;
        single[i].direction = Random().getRandomRadian();
        /*
        QTextStream out(stdout);
        out << (int) this->maxSpeed;
        */
        single[i].speed = Random().getRandomBetween(1, (int) this->maxSpeed)*(this->delay)/1000.0;
        single[i].stepX = cos(single[i].direction)*single[i].speed;
        single[i].stepY = sin(single[i].direction)*single[i].speed;
        single[i].alarm = Random().getRandomBetween(30, 1000);
    }
}

int InkDrop::validate(int amount, int radius, int startX, int startY, int maxX, int maxY, float maxSpeed) {

    // Trường hợp số hạt <= 0
    if (amount <= 0)
        return 1;

    // Bán kính kiểm tra <= 0
    if (radius <= 0)
        return 2;

    // Kích thước <= 0
    if (maxX <= 0)
        return 3;
    if (maxY <= 0)
        return 4;

    // Tọa độ xuất phát vượt quá maxX, maxY
    if (fabs(startX) >= maxX)
        return 5;
    if (fabs(startY) >= maxY)
        return 6;

    // Tốc độ xuất phát <= 0
    if (maxSpeed <= 0)
        return 7;

    return 0;
}

void InkDrop::update() {
    for (int i=0; i<amount; i++) {
        single[i].x += single[i].stepX;
        single[i].y += single[i].stepY;
        single[i].alarm--;

        if (single[i].alarm==0) {
            single[i].direction = Random().getRandomRadian();
            single[i].stepX = cos(single[i].direction)*single[i].speed;
            single[i].stepY = sin(single[i].direction)*single[i].speed;
            single[i].alarm = Random().getRandomBetween(30, 1000);
        }

        if (fabs(single[i].x) >= maxX || fabs(single[i].y) >= maxY) {
            fixPosition(&single[i]);
        }
    }
}

void InkDrop::fixPosition(SingleDrop* single) {

    const float _2_PI = 2*M_PI;

    // Với trường hợp hạt không nẩy lại
    // Chỉ cần đặt speed = 0 để hạt ngừng di chuyển
    if (this->mode == 1) {
        single->speed = 0;
    }

    // Trường hợp hạt có nẩy lại
    // cần thay đổi góc di chuyển
    if (this->mode == 2) {

        // Khi hạt chạm cạnh trên hooặc dưới
        if (fabs(single->y) >= this->maxY) {
            single->direction = _2_PI - single->direction;
        }

        // Khi hạt chạm cạnh trái hoặc phải
        // Nhưng có chiều hướng từ trên xuống
        if (fabs(single->x) >= this->maxX && single->direction >= M_PI) {
            single->direction = 3*M_PI - single->direction;
        }

        // Khi hạt chạm cạnh trái hoặc phải
        // Nhưng có chiều hướng từ dưới lên
        if (fabs(single->x) >= this->maxX && single->direction < M_PI) {
            single->direction = M_PI - single->direction;
        }

        if (single->direction >= _2_PI) {
            single->direction -= _2_PI;
        }
        single->stepX = cos(single->direction)*single->speed;
        single->stepY = sin(single->direction)*single->speed;

        /*
        if ((single->x) > maxX) {
            single->x = 2*maxX - single->x;
        }
        if ((single->x) < -maxX) {
            single->x = -2*maxX - single->x;
        }
        if ((single->y) < -maxY) {
            single->y = 2*maxY - single->y;
        }
        if ((single->y) < -maxY) {
            single->y = -2*maxY- single->y;
        }
        */
    }

}

int InkDrop::getCount() {
    int count = 0;
    float distance = 0;
    float sX, sY;

    for (int i=0; i<this->amount; i++) {
        sX = single[i].x - startX;
        sY = single[i].y - startY;
        distance = sqrt(sX*sX + sY*sY);
        //QTextStream out(stdout);
        //out << distance;
        if (distance < radius && single[i].speed>0) {
            count++;
        }
    }

    return count;
}
