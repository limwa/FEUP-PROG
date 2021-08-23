#include <iostream>
#include <math.h>
#include <limits>

#define PI 3.14159265

using namespace std;

int read_float(string prompt) {
    while (true) {
        float result;

        cout << prompt << flush;
        cin >> result;

        if (cin.peek() == '\n' && !cin.fail() && result >= 0)
            return result;

        cout << "Bad input! Please try again." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main(int, char**) {
    float lower = read_float("Please specify a lower bound: ");
    float upper = read_float("Please specify an upper bound: ");
    float increment = read_float("Please specify an increment: ");

    cout << endl;

    cout << "  ang   \t  sin   \t  cos   \t  tan" << endl;
    
    cout << fixed;
    cout.precision(6);
    for (float angle = lower; angle <= upper; angle += increment) {
        double rads = angle * PI / 180;
        cout << angle << '\t' << sin(rads) << '\t' << cos(rads) << '\t';
        if (static_cast<int> (round(angle - 90)) % 180 == 0) {
            if (static_cast<int> (round(angle - 90)) % 360 != 0)
                cout << '-';
            cout << "infinite";
        } else
            cout << tan(rads);

        cout << endl;
    }

    return 0;
}
