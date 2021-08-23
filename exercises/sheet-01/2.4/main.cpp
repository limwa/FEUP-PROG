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
    float weight = read_float("Please specify the weight of the merchandise (in grams): ");

    cout << endl;

    float cost = 5;
    if (weight > 500) {
        if (weight <= 1000) {
            cost += 1.5 * ceil((weight - 500) / 100);
        } else {
            cost += 12 * ceil((weight - 1000) / 250);
        }
    }

    cout << "The cost for transporting such merchandise is " << cost << '.' << endl;
    return 0;
}
