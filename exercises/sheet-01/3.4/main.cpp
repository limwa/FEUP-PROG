#include <iostream>
#include <limits>
#include <math.h>

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

unsigned read_unsigned(string prompt) {
    while (true) {
        unsigned result;

        cout << prompt << flush;
        cin >> result;

        if (cin.peek() == '\n' && !cin.fail())
            return result;

        cout << "Bad input! Please try again." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double round(double x, unsigned n) {
    return floor(x * pow(10, n) + 0.5) / pow(10, n);
}

int main(int, char**) {
    double x = read_double("Please specify a number to round: ");
    double n = read_unsigned("Please specify a number of decimal places to round to: ");

    cout << x << " rounded to " << n << " decimal places is " << round(x, n) << endl;
    return 0;
}
