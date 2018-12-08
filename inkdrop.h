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
 * @param singleDrop Mảng chứa thông tin về từng hạt
 */
class InkDrop
{
private:
    int amount;
    int count;
    int freq;
    int startX, startY;
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
    SingleDrop* getSingleDrop();
    InkDrop();
    InkDrop(int amount, int freq, int startX, int startY);
    void update();
};

#endif // INKDROP_H
