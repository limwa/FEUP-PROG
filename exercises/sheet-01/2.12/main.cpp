#include <iostream>
#include <limits>

using namespace std;

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
    double precision = read_double("Please specify a precision for the calculation: ");
    double result = 0;

    int denominator = 1;
    int sign = 1;

    double variation;
    do {
        variation = 4.0 / denominator;
        result += sign * variation;

        denominator += 2;
        sign = -sign;
    } while (variation > precision);

    cout.precision(8);

    cout << endl;
    cout << "The calculated value for pi is " << result << endl;
}
