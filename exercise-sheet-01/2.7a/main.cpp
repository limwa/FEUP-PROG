#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

unsigned int read_unsigned_int(string prompt) {
    while (true) {
        unsigned int result;

        cout << prompt << flush;
        cin >> result;

        if (cin.peek() == '\n' && !cin.fail())
            return result;

        cout << "Bad input! Please try again." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
int main(int, char**) {
    unsigned int n = read_unsigned_int("Please specify a number: ");
    
    cout << endl;

    bool is_prime = n > 1;
    for (unsigned int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }

    if (is_prime) {
        cout << "The provided number is prime!" << endl;
    } else {
        cout << "The provided number is not prime!" << endl;
    }

    return 0;
}
