#include <iostream>
#include <limits>

#include <iostream>
#include <limits>

using namespace std;

bool read_fraction(int &numerator, int &denominator) {
    char sep;
    cin >> numerator >> sep >> denominator;

    bool success = !cin.fail() && sep == '/' && denominator != 0 && cin.peek() == '\n';

    if (!success) {
        numerator = 0;
        denominator = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return success;
}

int main(int, char**) {
    cout << "Please specify a fraction: " << flush;
    
    int numerator, denominator;
    if (read_fraction(numerator, denominator))
        cout << endl << "The specified fraction (" << numerator << '/' << denominator << ") is valid." << endl;
    else
        cout << endl << "The given input is invalid and the read fraction is (" << numerator << '/' << denominator << ")." << endl; 

    return 0;   
}
