#include <iostream>
#include <math.h>

using namespace std;

int main(int, char**) {
    for (int n = 2; n < 1000; n++) {
        bool is_prime = n > 1;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            cout << n <<'\n';
    }

    cout << flush;

    return 0;
}
