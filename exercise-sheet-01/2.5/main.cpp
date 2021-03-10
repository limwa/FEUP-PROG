#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

float read_float(string prompt) {
    while (true) {
        float result;

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
    cout << "Ax^2 + Bx + C = 0" << endl << endl;

    float a = read_float("A? ");
    if (a == 0) {
        cout << "The value provided for A is not valid!" << endl;
        return 1;
    }

    float b = read_float("B? ");
    float c = read_float("C? ");

    cout << endl << fixed;
    cout.precision(3);

    float delta = b * b - 4 * a * c;
    if (delta == 0) {
        float result = (-b + sqrt(delta)) / (2 * a);
        cout << "The polynomial has 2 equal real roots." << endl << "x = " << result << endl;
    } else if (delta > 0) {
        float result1 = (-b + sqrt(delta)) / (2 * a);
        float result2 = (-b - sqrt(delta)) / (2 * a);
        cout << "The polynomial has 2 different real roots." << endl << "x1 = " << result1 << " and x2 = " << result2 << endl; 
    } else { // Delta is negative
        float imaginary = abs(sqrt(-delta) / (2 * a));
        float real = -b / (2 * a);
        cout << "The polynomial has 2 complex roots." << endl << "x1 = " << real << '+' << imaginary<< "i and x2 = " << real << '-' << imaginary << 'i' << endl;
    }

    return 0;
}
