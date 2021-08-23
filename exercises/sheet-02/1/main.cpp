#include <iostream>
#include "date.h"
#include "limwa.h"

using namespace std;


int main(int, char **) {
    // a)
    cout << "==== Year Month Day Test ====" << endl;

    unsigned int year, month, day;
    bool success;

    success = limwa::prompt("Please insert a year: ", "Please provide a valid year", year)
        && limwa::prompt("Please insert a month: ", "Please provide a month year", month)
        && limwa::prompt("Please insert a day: ", "Please provide a valid day", day);

    if (!success)
        return 1;

    cout << endl;

    Date date1(year, month, day);
    cout << "Year: " << date1.getYear() << '\n'
        << "Month: " << date1.getMonth() << '\n'
        << "Day: " << date1.getDay() << '\n'
        << "Date: " << date1.getDate() << '\n'
        << "Representation: ";

    date1.show();
    cout << '\n';

    cout << endl;

    cout << "==== yyyy/mm/dd Test ====" << endl;

    string yyyymmdd;

    success = limwa::prompt("Please insert a date (yyyy/mm/dd): ", "Please insert a valid date", yyyymmdd);

    if (!success)
        return 1;

    cout << endl;

    Date date2(yyyymmdd);
    cout << "Year: " << date2.getYear() << '\n'
        << "Month: " << date2.getMonth() << '\n'
        << "Day: " << date2.getDay() << '\n'
        << "Date: " << date2.getDate() << '\n'
        << "Representation: ";
    
    date2.show();
    cout << '\n';

    cout << endl;

    cout << "==== Setters Test ====" << endl;

    success = limwa::prompt("Please insert a year: ", "Please provide a valid year", year)
        && limwa::prompt("Please insert a month: ", "Please provide a month year", month)
        && limwa::prompt("Please insert a day: ", "Please provide a valid day", day);

    if (!success)
        return 1;

    cout << endl;

    date1.setYear(year);
    date1.setMonth(month);
    date1.setDay(day);

    cout << "Year: " << date1.getYear() << '\n'
        << "Month: " << date1.getMonth() << '\n'
        << "Day: " << date1.getDay() << '\n'
        << "Date: " << date1.getDate() << '\n'
        << "Representation: ";

    date1.show();
    cout << '\n';

    cout << endl;
}
