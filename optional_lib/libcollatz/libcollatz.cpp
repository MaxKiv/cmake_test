#include "libcollatz.h"

int update(int& in) {
    if (in % 2 == 0) {
        in /= 2;
    } else {
        in = (3 * in) + 1;
    }
    return in;
}