#include <iostream>

int main(int, char**) {
    char character;
    std::cout << "Please specify a character: " << std::flush;
    std::cin >> character;
    std::cout << int(character) << std::endl;
}
