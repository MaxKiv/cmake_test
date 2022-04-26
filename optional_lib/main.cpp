#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>

#include "libcollatz.h"

template <typename T>
void printVector (std::vector<T>& vector) {
    for(const auto& el: vector) {
        std::cout << "{" << el << "} ";
    }
    std::cout << std::endl;
}

int main() {
    auto meme = INTMAX_MAX << 1;
    std::cout << meme << std::endl;
}