#include "inkdrop.h"
#include "random.h"
#include "math.h"

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

InkDrop::InkDrop()
{}

InkDrop::InkDrop(int amount, int freq, int startX, int startY) {
    setAmount(amount);
    setFreq(freq);
    setStart(startX, startY);
    single = new SingleDrop[amount];
    initSingle();
}

void InkDrop::initSingle() {
    for (int i=0; i<amount; i++) {
        single[i].x = startX;
        single[i].y = startY;
        single[i].direction = Random().getRandomRadian();
        single[i].speed = Random().getRandomBetween(0, 100)/100.0;
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
    }
}
