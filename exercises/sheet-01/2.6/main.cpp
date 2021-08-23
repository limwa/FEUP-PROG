#include <iostream>
#include <limits>

using namespace std;

int read_int(string prompt) {
    while (true) {
        int result;

        cout << prompt << flush;
        cin >> result;

        if (cin.peek() == '\n' && !cin.fail() && result > 0)
            return result;

        cout << "Bad input! Please try again." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main(int, char**) {
    int years = read_int("Please specify the number of years for the interest plan: ");
    float ammount = static_cast<float> (read_int("Please specify the ammount that will be deposited: "));
    float rate = read_int("Please specify the annual interest rate (in %): ") / 100.0;

    cout << endl;
    
    for (int i = 0; i < years; i++) {
        ammount *= (1 + rate);
    }

    cout << "After " << years << " years, you will be able to withdraw " << ammount << "€." << endl;
}
