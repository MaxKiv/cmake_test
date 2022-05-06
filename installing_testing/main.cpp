#include <iostream>
#include <string>
#include <vector>

#include "libCollatzConfig.h"
#ifdef USE_COLLATZ
#   include "libcollatz.h"
#endif

template <typename T>
void printVector(std::vector<T>& vector) {
    for (const auto& el : vector) {
        std::cout << "{" << el << "} ";
    }
    std::cout << std::endl;
}

int main() {
    unsigned int num = 1000;
    for (int init = -100; init < 100; init++) {
        int value = init;
        for (size_t i = 0; i < num; i++) {
            #ifdef USE_COLLATZ
                value = updateFast(value);
            #else
                value = value++;
            #endif
        }
        std::cout << value << std::endl;
    }
    return 0;
}