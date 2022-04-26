#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>

#include "libpower.hpp"

template <typename T>
void printVector (std::vector<T>& vector) {
    for(const auto& el: vector) {
        std::cout << "{" << el << "} ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "first some bullshit" << std::endl;

    std::map<int, int> mappie{{1,100}, {2,200}, {3,300}};
    std::string init = "";
    std::string out = std::accumulate(std::begin(mappie), std::end(mappie), init, [](std::string out, std::map<int, int>::value_type& p) { return out + std::to_string(p.second); });
    std::cout << std::stoi(out)*100 << std::endl;

    std::cout << "Then some more bullshit" << std::endl;

    std::map<unsigned short, std::string> Map2 {{1,"A"},{2,"B"},{3,"C"},{4,"D"},{5,"E"},{6,"F"}};

    std::string out2 = std::accumulate(std::begin(Map2), std::end(Map2), init, [](std::string out, std::map<unsigned short, std::string>::value_type& entry){return out + std::to_string(entry.first) + " " + entry.second + " ";});
    std::cout << out2;

    std::vector<std::string> inputVector{"a","b","c","d"};
    std::cout << "POWER set:\n";
    printVector(inputVector);
    std::vector<std::string> out3 = powerSet(inputVector);
    std::cout << "result:\n";
    printVector(out3);

    return 0;
}