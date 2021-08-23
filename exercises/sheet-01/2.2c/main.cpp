#include <iostream>
#include <limits>

using namespace std;

float read_float(string prompt) {
    while (true) {
        float result;

        cout << prompt << flush;
        cin >> result;

        if (!cin.fail() && result > 0)
            return result;

        cerr << "Bad input! Please try again." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main(int, char**) {
    float output_first, output_second, output_third;

    float first = read_float("First number? ");
    output_first = first;

    float second = read_float("Second number? ");
    if (second > output_first) {
        output_second = output_first;
        output_first = second;
    } else
        output_second = second;

    float third = read_float("Third number? ");
    if (third > output_second) {
        output_third = output_second;
        output_second = third;

        if (third > output_first) {
            output_second = output_first;
            output_first = third;
        }
    } else
        output_third = third;

    cout << endl;

    if (output_first < output_second + output_third) {
        cout << "It's possible to build a triangle with sides equal to these lengths." << endl;
    } else {
        cout << "It's *not* possible to build a triangle with sides equal to these lengths." << endl;
    }
}
