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
    unsigned int number = read_unsigned_integer("Please specify a number: ");

    cout << endl;
    cout << number << " = ";

    if (number == 1) {
        cout << '1' << endl;
        return 0;
    }

    int div = 2;
    bool start = true;
    while (number > 1) {
        while (number % div == 0) {
            number /= div;
            if (start)
                start = false;
            else
                cout << " x ";

            cout << div;

            if (start)
                start = false;
        }

        div += (div == 2 ? 1 : 2);
    }

    cout << endl;

    return 0;
}
