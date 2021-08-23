#include "math.h"
#include "limwa.h"

using namespace std;

bool is_leap_year(unsigned int year);
bool is_month_valid(unsigned int month);
bool is_day_valid(unsigned int day, unsigned int month, unsigned int year);
unsigned int get_days_in_month(unsigned int month, unsigned int year);
int get_month_code(unsigned int month, unsigned int year);
int get_day_of_week(unsigned int day, unsigned int month, unsigned int year);
string get_month_name(unsigned int month);

int main(int, char**) {
    unsigned int year, month, day;
    limwa::read_value<unsigned int>("Please specify a year: ", "Invalid year!", year);
    limwa::read_value<unsigned int>("Please specify a month: ", "Invalid month!", month, is_month_valid);
    limwa::read_value<unsigned int>("Please specify a day: ", "Invalid day!", day, 
        [month, year](auto res) { return is_day_valid(res, month, year); }
    );

    cout << endl;
    cout << get_month_name(month) << ' ';

    cout << day;
    switch (day % 10) {
        case 1:
            cout << "st";
            break;

        case 2:
            cout << "nd";
            break;

        case 3:
            cout << "rd";
            break;

        default:
            cout << "th";
            break;
    }

    cout << ' ' << year << " is a ";

    switch (get_day_of_week(day, month, year)) {
        case 0:
            cout << "Sunday";
            break;

        case 1:
            cout << "Saturday";
            break;

        case 2:
            cout << "Monday";
            break;

        case 3:
            cout << "Tuesday";
            break;

        case 4:
            cout << "Wednesday";
            break;

        case 5:
            cout << "Thursday";
            break;

        case 6:
            cout << "Friday";
            break;

        default:
            cout << "Hell's Gate";
            break;
    }

    cout << endl;
}

bool is_leap_year(unsigned int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

bool is_month_valid(unsigned int month) {
    return month >= 1 && month <= 12;
}

bool is_day_valid(unsigned int day, unsigned int month, unsigned int year) {
    return day <= get_days_in_month(month, year);
}

unsigned int get_days_in_month(unsigned int month, unsigned int year) {
    if (!is_month_valid(month))
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

int get_month_code(unsigned int month, unsigned int year) {
    if (!is_month_valid(month))
        return -1;

    switch (month) {
        case 1:
            return is_leap_year(year) ? 6 : 0;

        case 2:
            return is_leap_year(year) ? 2 : 3;

        case 3:
        case 11:
            return 3;

        case 4:
        case 7:
            return 6;

        case 5:
            return 1;

        case 6:
            return 4;
            
        case 8:
            return 2;

        case 9:
        case 12:
            return 5;

        default:
            return 0;
    }
}

int get_day_of_week(unsigned int day, unsigned int month, unsigned int year) {
    if (!is_month_valid(month) || !is_day_valid(day, month, year))
        return -1;

    unsigned int year_length = log10(year) + 1;
    unsigned int s = year / pow(10, year_length - 2);
    unsigned int a = year % 100;
    unsigned int c = get_month_code(month, year);

    return ((unsigned int) (1.25 * a) + c + day - 2 * (s % 4) + 7) % 7;
}

string get_month_name(unsigned int month) {
    if (!is_month_valid)
        return string();

    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";

        default: return string();
    }
}