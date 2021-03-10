#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

int read_integer(string prompt) {
    while (true) {
        int result;

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
    int number1 = read_integer("Please specify a number: ");
    int number2 = read_integer("Please specify a number: ");

    cout << endl;

    if (number1 > 0 && number2 > 0) {
        int max_size = numeric_limits<int>::max() - number1;
        if (number2 > max_size) {
            cout << "Sum Overflow!" << endl;
            return 0;
        }
    } else if (number1 < 0 && number2 < 0) {
        int min_size = numeric_limits<int>::min() - number1;
        if (number2 < min_size) {
            cout << "Sum Underflow!" << endl;
            return 0;
        }
    }

    cout << "The value of the sum is " << number1 + number2 << '.'<< endl;
}
