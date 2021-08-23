#include <iostream>
#include <limits>

using namespace std;

unsigned int read_unsigned_int(string prompt) {
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

unsigned int gcd_through_returned_value(unsigned int n1, unsigned int n2) {
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

void gcd_through_reference(unsigned int n1, unsigned int n2, unsigned int &result) {
    result = n1 > n2 ? n1 : n2;
    unsigned int smallest = n1 < n2 ? n1 : n2;
    
    unsigned int remainder;
    while (smallest != 0 && smallest != result) {
        remainder = result % smallest;
        result = smallest;
        smallest = remainder;
    }
}

int main(int, char**) {
    unsigned int a = read_unsigned_int("Please provide a number: ");
    unsigned int b = read_unsigned_int("Please provide another number: ");

    unsigned int gcd_returned = gcd_through_returned_value(a, b);
    unsigned int gcd_reference;
    gcd_through_reference(a, b, gcd_reference);

    cout << endl;
    cout << "The greatest common divisor of " << a << " and " << b << " (returned) is " << gcd_returned << endl;
    cout << "The greatest common divisor of " << a << " and " << b << " (reference) is " << gcd_reference << endl;

    return 0;
}
