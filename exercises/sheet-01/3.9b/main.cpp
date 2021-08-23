#include "limwa.h"

using namespace std;

bool is_leap_year(unsigned int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

unsigned int get_days_in_month(unsigned int month, unsigned int year) {
    if (month < 1 || month > 12)
        return 0;

    switch (month) {
        case 2:
            return is_leap_year(year) ? 29 : 28;
        
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        default:
            return 30;
    }
}

int main(int, char**) {
    unsigned int year, month;
    limwa::read_value<unsigned int>("Please specify a month: ", "Invalid month!", month, [](auto res) { return res >= 1 && res <= 12; });
    limwa::read_value<unsigned int>("Please specify a year: ", "Invalid year!", year);

    cout << endl;
    cout << "Month " << month << " of year " << year << " has " << get_days_in_month(month, year) << " days" << endl;
}
