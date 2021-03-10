#include <iostream>
#include <limits>

using namespace std;

float read_float(string prompt) {
    while (true) {
        float result;

        cout << prompt << flush;
        cin >> result;

        if (!cin.fail())
            return result;

        cout << "Bad input! Please try again." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main(int, char**) {
    cout << "ax + by = c" << endl << "dx + ey = f" << endl << endl;
    
    float a = read_float("a? ");
    float b = read_float("b? ");
    float c = read_float("c? ");
    float d = read_float("d? ");
    float e = read_float("e? ");
    float f = read_float("f? ");

    cout << endl;

    float n1 = c * e - b * f;
    float n2 = a * f - c * d;
    float denominator = a * e - b * d;
    
    if (n1 == 0 && n2 == 0) {
        cout << "System has infinitely many solutions." << endl;
    } else {
        if (denominator == 0) {
            cout << "System is impossible!" << endl;
            return 0;
        }
    }

    float x = n1 / denominator;
    float y = n2 / denominator;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}
