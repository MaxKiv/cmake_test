#include <vector>
#include <cmath>
// calculate power set of input vector
template <typename T>
std::vector<T> powerSet(std::vector<T>& inputVector) {
    // str[000]
    // str[001]
    // str[010]
    // str[011]
    std::vector<T> out;
    for (size_t i = 0; i < std::pow(2,inputVector.size()); i++) {
        {
            for(size_t bitIdx = 1; bitIdx < inputVector.size(); bitIdx++) {
                auto out = i<<bitIdx;
                std::cout << " i << bitIdx " << out << std::endl;
            }
            std::cout << std::endl;
        }
    }
    return out;
}