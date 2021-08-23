#include <iostream>
#include <limits>

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

int main(int, char**) {
    unsigned int num_terms = read_unsigned_integer("Please specify a number of terms: ");
    double result = 0;

    int denominator = 1;
    int sign = 1;

    for (unsigned int i = 0; i < num_terms; i++) {
        result += sign * 4.0 / denominator;

        denominator += 2;
        sign = -sign;
    }

    cout.precision(8);

    cout << endl;
    cout << "The calculated value for pi is " << result << endl;
}
