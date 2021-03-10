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
    float first = read_float("First number? ");
    float largest = first;
    float smallest = first;

    float second = read_float("Second number? ");
    if (second > largest)
        largest = second;
    
    if (second < smallest)
        smallest = second;

    float third = read_float("Third number? ");
    if (third > largest)
        largest = third;
    
    if (third < smallest)
        smallest = third;

    cout << "The largest number you've provided is " << largest << endl;
    cout << "The smallest number you've provided is " << smallest << endl; 
}