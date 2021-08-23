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

bool is_prime(unsigned int number) {
    bool result = number > 1;
    for (unsigned int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            result = false;
            break;
        }
    }

    return result;
}

int main(int, char**) {
    unsigned int n = read_unsigned_int("Please specify a number: ");
    
    cout << endl;

    if (is_prime(n)) {
        cout << "The provided number is prime!" << endl;
    } else {
        cout << "The provided number is not prime!" << endl;
    }

    return 0;
}
