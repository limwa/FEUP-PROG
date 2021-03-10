#include <iostream>

int main(int, char**) {
    int a, b, c;
    std::cout << "Please, input 3 integer numbers" << std::endl;
    std::cout << "A? " << std::flush;
    std::cin >> a;
    std::cout << "B? " << std::flush;
    std::cin >> b;
    std::cout << "C? " << std::flush;
    std::cin >> c;

    float mean = (a + b + c) / 3.0;
    float diff_a = a - mean;
    float diff_b = b - mean;
    float diff_c = c - mean;

    std::cout << "mean\t= " << mean << "\nA-mean\t= " << diff_a << "\nB-mean\t= " << diff_b << "\nC-mean\t= " << diff_c << std::endl;
    return 0;
}
