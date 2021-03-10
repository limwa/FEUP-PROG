#include <iostream>
#include <math.h>

using namespace std;

int main(int, char**) {
    int prime_count = 0;
    int n = 2;

    while (prime_count < 100) {
        bool is_prime = n > 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            cout << n <<'\n';
            prime_count++;
        }

        n++;
    }

    cout << flush;

    return 0;
}
