#include <iostream>
#include <limits>

using namespace std;

bool read_int(int &x) {
    cin >> x;

    bool success = cin.peek() == '\n' && !cin.fail();

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return success;
}

int main(int, char**) {
    cout << "Please specify a number: " << flush;

    int number;
    bool success = read_int(number);

    cout << endl << "The given input is ";
    if (success)
        cout << "valid (" << number << ')';
    else
        cout << "invalid";

    cout << '.' << endl;
}
