#include <iostream>
#include <ctime>

int main(int, char**) {
    srand ( time(NULL) ); rand();

    while (true) {
    int r_number = rand() % (9 - 2 + 1) + 2;

    std::cout << r_number << std::endl;
    }
}
