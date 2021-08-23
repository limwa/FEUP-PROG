#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

double read_positive_double(string prompt) {
    while (true) {
        double result;

        cout << prompt << flush;
        cin >> result;

        if (cin.peek() == '\n' && !cin.fail() && result >= 0)
            return result;

        cout << "Bad input! Please try again." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

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

unsigned int get_decimal_places_from_number(double number) {
    if (number >= 1 || number <= 0)
        return 0;

    return -floor(log10(number));
}

int main(int, char**) {
    double number = read_positive_double("Please specify a number: ");
    double precision = read_positive_double("Please specify a precision: ");
    unsigned int max_iterations = read_unsigned_int("Please specify a maximum number of iterations: ");

    cout << endl;

    double rq = 1;
    for (unsigned int i = 0; i < max_iterations; i++) {
        double rqn = (rq + number / rq) / 2;
        double delta = abs(rq - rqn);
        rq = rqn;
        if (delta < precision)
            break;
    }

    cout << "The square root method says that the square root of " << number << " is " << sqrt(number) << number << endl;
    
    cout.precision(get_decimal_places_from_number(precision) + 1);
    cout << "The square root of " << number << " is aproximately " << rq << endl;
}
