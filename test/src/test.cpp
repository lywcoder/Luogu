#include <iostream>

int main() {
    std::string s = "Hello World!";
    // for (auto c : s) {
    //     std::cout << c << " ";
    // }
    for (auto &c : s) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    for (const auto &c : s) {
        std::cout << c << " ";
    }
}