#include "limwa.h"

using namespace std;

bool is_leap_year(unsigned int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int main(int, char**) {
    unsigned int year;
    limwa::read_value<unsigned int>("Please specify a year: ", "Invalid number!", year);

    cout << endl;
    cout << year << " is ";
    if (!is_leap_year(year))
        cout << "not ";

    cout << "a leap year." << endl;
}
