#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

int main(int, char**) {
    unsigned long n = numeric_limits<unsigned long>::max();

    while (n >= 2) {
        bool is_prime = true;
        for (unsigned long i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            break;

        n--;
    }

    cout << "The greatest prime unsigned long is " << n << endl;
    return 0;
}
