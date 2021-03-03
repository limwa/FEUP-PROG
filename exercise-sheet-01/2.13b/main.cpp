#include <iostream>
#include <math.h>
#include <vector>
#include <limits>

using namespace std;

int read_integer(string prompt) {
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
    
    vector<int> numbers;
    while (int number = read_integer("Please specify a number: ")) {
        numbers.push_back(number);

        sum += number;
        if (number < smallest)
            smallest = number;

        if (number > largest)
            largest = number;
    }

    mean = sum / numbers.size();
    
    for (int number : numbers) {
        sd += pow(number - mean, 2);
    }

    sd = sqrt(sd / (numbers.size() - 1));

    cout << endl << numbers.size() << (numbers.size() == 1 ? " number was read." : " numbers were read.") << endl;
    cout << endl << "Sum: " << sum << endl << "Mean: " << mean << endl << "Standard Deviation: " << sd << endl;
    cout << endl << "Largest Value: " << largest << endl << "Smallest Value: " << smallest << endl;
    return 0;
}
