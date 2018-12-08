#include "random.h"
#include "ctime"
#include "cstdlib"
#include "cmath"

Random::Random()
{}

int Random::getRandomBetween(int begin, int end) {
    if (begin > end) return begin;
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    /* using nano-seconds instead of seconds */
    srand((time_t)ts.tv_nsec);

    return (begin + (rand() % (end - begin)));
}

float Random::getRandomRadian() {
    int degree = getRandomBetween(0, 360);
    return (degree/180.0 * M_PI);
}
