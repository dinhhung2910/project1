#ifndef INKDROP_H
#define INKDROP_H
#include "singledrop.h"

/**
 * @brief The InkDrop class
 * Giọt mực
 * @param amount Số lượng hạt
 * @param count Đếm số hạt nằm trong vòng tròn bán kính R kể từ vị trí bắt đầu
 * @param freq Tấn số thay đổi
 * @param startX Hoành độ bắt đầu
 * @param startY Tung độ bắt đầu
 * @param maxX, maxY Tọa độ tối đa của X, Y. Bằng 1/2 kích thước màn hình
 * @param radius Bán kính cần kiểm tra xung quanh tâm giọt mực
 * @param singleDrop Mảng chứa thông tin về từng hạt
 */
class InkDrop
{
private:
    int amount;
    int count;
    int freq;
    int radius;
    int startX, startY;
    int maxX, maxY;
    char mode;
    float maxSpeed;

    void fixPosition(SingleDrop* single);

protected:
    SingleDrop* single;
    void initSingle();
public:
    void setAmount(int amount);
    int getAmount();
    void setFreq(int freq);
    int getFreq();
    void setStart(int startX, int startY);
    int getStartX();
    int getStartY();
    void setMax(int maxX, int maxY);
    int getMaxX();
    int getMaxY();
    void setMode(char mode);
    int getMode();
    void setRadius(int radius);
    int getRadius();
    SingleDrop* getSingleDrop();
    InkDrop();
    InkDrop(int amount, int freq, int startX, int startY, int maxX, int maxY, int radius, int mode);
    void update();
};

#endif // INKDROP_H
