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
    static int getRandomBetween(int begin, int end);
};

#endif // RANDOM_H
