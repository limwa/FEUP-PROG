#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

int readInteger(string prompt) {
    while (true) {
        int result;

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
    float sum = 0, mean = 0, sd = 0;
    int smallest = numeric_limits<int>::max();
    int largest = numeric_limits<int>::min(); 

    int size = readInteger("Please specify how many numbers there are in the sequence: ");
    if (size <= 0)
        return 0;

    cout << endl;
    
    int numbers[size]; 
    for (int i = 0; i < size; i++) {
        int number = readInteger("Please specify a number: ");
        numbers[i] = number;

        sum += number;
        if (number < smallest)
            smallest = number;

        if (number > largest)
            largest = number;
    }

    mean = sum / size;
    
    for (int number : numbers) {
        sd += pow(number - mean, 2);
    }

    sd = sqrt(sd / (size - 1));

    cout << endl << "Sum: " << sum << endl << "Mean: " << mean << endl << "Standard Deviation: " << sd << endl << endl;
    cout << "Largest Value: " << largest << endl << "Smallest Value: " << smallest << endl;
}
