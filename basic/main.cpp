#include <algorithm>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    std::vector<std::string> stringVector(argc, "");
    for (size_t i = 0; i < argc; i++) {
        stringVector[i] = (std::string(argv[i]));
    }

    for (const auto& string : stringVector) {
        std::cout << string << std::endl;
    }

    return 0;
}