#ifndef RANDOM_H
#define RANDOM_H

/**
 * @brief The Random class
 * Các hàm tính số ngẫu nhiên
 */
class Random
{
public:
    Random();
    /**
     * @brief getRandomRadian
     * @return số đo góc ngẫu nhiên (radian)
     */
    static float getRandomRadian();

    /**
     * @brief getRandomBetween
     * @param begin Số nhỏ
     * @param end Số lớn
     * @return Một số ngẫu nhiên nằm giữa số nhỏ và số lớn
     */
    static int getRandomBetween(int begin, int end);
};

#endif // RANDOM_H
