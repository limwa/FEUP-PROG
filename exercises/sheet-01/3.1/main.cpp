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

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x2, y2, x3, y3);
    double s = 0.5 * (a + b + c);

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(int, char**) {
    float x1 = read_float("x1 = ");
    float y1 = read_float("y1 = ");
    float x2 = read_float("x2 = ");
    float y2 = read_float("y2 = ");
    float x3 = read_float("x3 = ");
    float y3 = read_float("y3 = ");

    cout << "Area = " << area(x1, y1, x2, y2, x3, y3) << endl;
    return 0;
}
