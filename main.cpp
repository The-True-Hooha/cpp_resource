#include <iostream>
#include <format>

int main() {
    std::string name = "World";
    std::cout << std::format("Hello, {}!\n", name);
    return 0;
}
