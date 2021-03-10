#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

unsigned int read_unsigned_integer(string prompt) {
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

unsigned int get_digit_at(unsigned int number, unsigned int index) {
    return static_cast<unsigned int> (number / pow(10, index)) % 10;
}

int main(int, char**) {
    unsigned int number = read_unsigned_integer("Please specify a three-digit number: ");
    if (number < 100 || number > 999) {
        cout << "The number " << number << " is not a three-digit number." << endl;
        return 0;
    }

    cout << endl;

    unsigned int inverted = 0;
    for (int i = 0; i <= log10(number); i++) {
        inverted = inverted * 10 + get_digit_at(number, i);
    }

    if (number == inverted) {
        cout << "The number " << number << " is a palindrome." << endl;
    } else {
        cout << "The number " << number << " is not a palindrome." << endl;
    }

    return 0;
}
