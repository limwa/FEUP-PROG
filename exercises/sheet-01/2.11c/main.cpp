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

double read_double(string prompt) {
    while (true) {
        double result;

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
    double x = read_double("Please specify a value for x: ");
    unsigned int num_terms = read_unsigned_integer("Please specify a number of terms: ");
    double result = 0;

    double numerator = 1;
    double denominator = 1;
    int sign = 1;

    for (unsigned int i = 1; i <= num_terms; i++) {
        result += sign * numerator / denominator;

        sign = -sign;
        numerator *= x;
        denominator *= i;
    }

    cout.precision(8);

    cout << endl;
    cout << "The calculated value for e^-x is " << result << endl;
}
