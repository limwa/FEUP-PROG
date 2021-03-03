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

    float x = (c * e - b * f) / (a * e - b * d);
    float y = (a * f - c * d) / (a * e - b * d);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
