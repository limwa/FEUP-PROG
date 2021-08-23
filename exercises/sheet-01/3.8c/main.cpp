#include <iostream>
#include <limits>

using namespace std;

bool read_fraction(int &numerator, int &denominator) {
    char sep;
    cin >> numerator >> sep >> denominator;

    bool success = !cin.fail() && cin.peek() == '\n';

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

void add(int &numerator1, int &denominator1, int &numerator2, int &denominator2, int &result_numerator, int &result_denominator) {
    result_numerator = numerator1 * denominator2 + numerator2 * denominator1;
    result_denominator = denominator1 * denominator2;

    reduce_fraction(result_numerator, result_denominator);
}

void subtract(int &numerator1, int &denominator1, int &numerator2, int &denominator2, int &result_numerator, int &result_denominator) {
    result_numerator = numerator1 * denominator2 - numerator2 * denominator1;
    result_denominator = denominator1 * denominator2;

    reduce_fraction(result_numerator, result_denominator);
}

void multiply(int &numerator1, int &denominator1, int &numerator2, int &denominator2, int &result_numerator, int &result_denominator) {
    result_numerator = numerator1 * numerator2;
    result_denominator = denominator1 * denominator2;

    reduce_fraction(result_numerator, result_denominator);
}

void divide(int &numerator1, int &denominator1, int &numerator2, int &denominator2, int &result_numerator, int &result_denominator) {
    result_numerator = numerator1 * denominator2;
    result_denominator = denominator1 * numerator2;

    reduce_fraction(result_numerator, result_denominator);
}

int main(int, char**) {
    int numerator1, denominator1, numerator2, denominator2, result_numerator, result_denominator;
    
    cout << "Please specify a fraction: " << flush;
    bool success1 = read_fraction(numerator1, denominator1);
    
    cout << "Please specify another fraction: " << flush;
    bool success2 = read_fraction(numerator2, denominator2);

    cout << endl;
    if (success1 && success2) {
        cout << "The specified fractions are " << numerator1 << '/' << denominator1 << " and " << numerator2 << '/' << denominator2 << endl << endl;

        add(numerator1, denominator1, numerator2, denominator2, result_numerator, result_denominator);
        cout << "Their sum is " << result_numerator << '/' << result_denominator << endl;
        
        subtract(numerator1, denominator1, numerator2, denominator2, result_numerator, result_denominator);
        cout << "Their difference is " << result_numerator << '/' << result_denominator << endl;
        
        multiply(numerator1, denominator1, numerator2, denominator2, result_numerator, result_denominator);
        cout << "Their product is " << result_numerator << '/' << result_denominator << endl;
        
        divide(numerator1, denominator1, numerator2, denominator2, result_numerator, result_denominator);
        cout << "Their quocient is " << result_numerator << '/' << result_denominator << endl;
    } else
        cout << "The given input is invalid" << endl;

    return 0;   
}
