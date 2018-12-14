#include "random.h"
#include "ctime"
#include "cstdlib"
#include "cmath"

Random::Random()
{}

/**
 * @brief Random::getRandomBetween
 * @param begin Số nhỏ
 * @param end Số lớn
 * @return Một số ngẫu nhiên nằm giữa số nhỏ và số lớn
 */
int Random::getRandomBetween(int begin, int end) {

    // Trường hợp số nhỏ lớn hơn số lớn thì tạm trả về số nhỏ
    if (begin > end) return begin;

    // Dùng thời gian  hiện tại của máy tính để làm seed cho hàm random
    // nanoseconds
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);

    return (begin + (rand() % (end - begin)));
}

float Random::getRandomRadian() {
    int degree = getRandomBetween(0, 360);
    return (degree/180.0 * M_PI);
}
