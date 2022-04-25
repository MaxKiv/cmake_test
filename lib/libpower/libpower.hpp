#include <vector>
#include <cmath>

template <typename T>
std::vector<T> powerSet(std::vector<T>& inputVector) {
    //
    std::vector<T> out;
    for (size_t i = 0; i < std::pow(2,inputVector.size()); i++) {
        {
            if(i|0b000) {
                out.push_back(inputVector[0b000]);
            }
            else if(i|0b001){
                out.push_back(out[0b001]);
            }
            else{

            }
        }
        // str[000]
        // str[001]
        // str[010]
        // str[011]
    }
    return out;
}