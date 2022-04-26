#include <cmath>
#include <vector>
// calculate power set of input vector
template <typename T>
std::vector<T> powerSet(std::vector<T>& inputVector) {
    // str[000]
    // str[001]
    // str[010]
    // str[011]
    std::vector<T> out;
    for (size_t i = 0; i < std::pow(2, inputVector.size()); i++) {
        T el;
        for (size_t bitIdx = 0; bitIdx < inputVector.size(); bitIdx++) {
            if((i >> bitIdx) & 1) {
                el += inputVector[bitIdx];
            }
        }
        out.push_back(el);
    }
    return out;
}