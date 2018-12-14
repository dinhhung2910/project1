#include "inkdrop.h"
#include "random.h"
#include "math.h"
#include "singledrop.h"

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

InkDrop::InkDrop()
{}

InkDrop::InkDrop(int amount, int freq, int startX, int startY, int maxX, int maxY, int radius, int mode) {
    setAmount(amount);
    setFreq(freq);
    setStart(startX, startY);
    setRadius(radius);
    single = new SingleDrop[amount];
    initSingle();
    setMode(mode);
    setMax(maxX, maxY);
}

void InkDrop::initSingle() {
    for (int i=0; i<amount; i++) {
        single[i].x = startX;
        single[i].y = startY;
        single[i].direction = Random().getRandomRadian();
        single[i].speed = Random().getRandomBetween(1, 1000)/100.0;
        single[i].stepX = cos(single[i].direction)*single[i].speed;
        single[i].stepY = sin(single[i].direction)*single[i].speed;
        single[i].alarm = Random().getRandomBetween(30, 1000);
    }
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
    }
}
