#include <iostream>

int main(int, char**) {
    const float PI = 3.141592653589793;

    float density, radius;
    std::cout << "Density (kg/m^3): " << std::flush;
    std::cin >> density;
    std::cout << "Radius (m): " << std::flush;
    std::cin >> radius;

    float mass = 4 * PI * density * (radius * radius * radius)  / 3;
    std::cout << "Mass (kg): " << mass << std::endl;
    return 0;
}
