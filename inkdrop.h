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
 * @param maxSpeed tốc độ tối đa của giọt mực (pixel per seconds)
 * @param delay Khoảng cách thời gian giữa 2 lần tính toán (ms)
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
    int delay;

    /**
     * @brief fixPosition Sửa lại vị trí của hạt mực khi nó đi ra ngoài
     * @param single hạt mực cần sửa
     */
    void fixPosition(SingleDrop* single);

protected:
    SingleDrop* single;
    void initSingle();
public:
    /* GET & SET */
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
    void setMaxSpeed(float maxSpeed);
    float getMaxSpeed();
    void setDelay(int delay);
    int getDelay();

    SingleDrop* getSingleDrop();

    /* CÁC PHƯƠNG THÚC KHỞI TẠO */
    /**
     * @brief InkDrop Khởi tạo mặc định
     */
    InkDrop();

    /**
     * @brief InkDrop
     * @param amount Số lượng hạt
     * @param freq
     * @param startX Tọa độ bắt đầu
     * @param startY Tọa độ bắt đầu
     * @param maxX Tọa độ tối đa (1/2 kích thước màn hình)
     * @param maxY Tọa độ tối đa (1/2 kích thuocs màn hình)
     * @param radius Bán kính vòng tròn cần kiểm tra quanh tâm
     * @param maxSpeed Tốc độ tối đa (pixel per seconds)
     * @param delay Khoảng cách thời gian giữa 2 lần tính liên tiếp
     * @param mode Chế độ: 1: hạt biến mất khi chạm tường, 2: hạt nảy lại
     */
    InkDrop(int amount, int freq, int startX, int startY, int maxX, int maxY, int radius, float maxSpeed, int delay, int mode);

    /**
     * @brief update cập nhật thông tin về giọt mực
     */
    void update();

    /**
     * @brief validate hàm kiểm tra tính hợp lệ của các trường đầu vào
     * @param amount
     * @param radius
     * @param startX
     * @param startY
     * @param maxX
     * @param maxY
     * @param maxSpeed
     * @return mã lỗi
     */
    static int validate(int amount, int radius, int startX, int startY, int maxX, int maxY, float maxSpeed);

    /**
     * @brief getCount
     * @return Số lượng hạt mực nằm trong vòng tròn bán kính R
     */
    int getCount();
};

#endif // INKDROP_H
