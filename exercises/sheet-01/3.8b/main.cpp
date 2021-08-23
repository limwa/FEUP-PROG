#include <iostream>
#include <limits>

using namespace std;

bool read_fraction(int &numerator, int &denominator) {
    char sep;
    cin >> numerator >> sep >> denominator;

    bool success = !cin.fail() && sep == '/' && cin.peek() == '\n';

    if (!success) {
        numerator = 0;
        denominator = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return success;
}

unsigned int gcd(unsigned int n1, unsigned int n2) {
    unsigned int greatest = n1 > n2 ? n1 : n2;
    unsigned int smallest = n1 < n2 ? n1 : n2;
    
    unsigned int remainder;
    while (smallest != 0 && smallest != greatest) {
        remainder = greatest % smallest;
        greatest = smallest;
        smallest = remainder;
    }

    return greatest;
}

void reduce_fraction(int &numerator, int &denominator) {
    if (denominator == 0)
        return;

    unsigned int divisor = gcd(numerator > 0 ? numerator : -numerator, denominator > 0 ? denominator : -denominator);

    numerator /= divisor;
    denominator /= divisor;

    if (numerator < 0 && denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int main(int, char**) {
    cout << "Please specify a fraction: " << flush;
    
    int numerator, denominator;
    if (read_fraction(numerator, denominator)) {
        cout << endl << "The specified fraction (" << numerator << '/' << denominator << ") is valid." << endl;

        reduce_fraction(numerator, denominator);
        cout << "It's reduced form is " << numerator << '/' << denominator << '.' << endl;
    } else
        cout << endl << "The given input is invalid and the read fraction is (" << numerator << '/' << denominator << ")." << endl; 

    return 0;   
}
