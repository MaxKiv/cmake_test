#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

int main(int argc, char* argv[]) {
    assert(argc == 3);
    std::istringstream iss2(argv[1]);
    int value;
    if(iss2 >> value) {
        std::cout << "arg 1: " << value << std::endl;
    }
    std::istringstream iss(argv[2]);
    unsigned int num; 
    if(iss >> num) {
        std::cout << "arg 2: " << num << std::endl;
    }
    for (size_t i = 0; i < num; i++) {
        #ifdef USE_COLLATZ
            value = updateFast(value);
        #else
            value = value++;
        #endif
    }
    std::cout << value << std::endl;
    return 0;
}