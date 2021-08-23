#pragma once
#include <string>

using namespace std;

class Date {
    public:
        // a)
        Date(unsigned int year, unsigned int month, unsigned int day);
        Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
        void setYear(unsigned int year);
        void setMonth(unsigned int month);
        void setDay(unsigned int day);
        void setDate(unsigned int year, unsigned int month, unsigned int day);
        unsigned int getYear() const;
        unsigned int getMonth() const;
        unsigned int getDay() const;
        string getDate() const; // returns the date in format "yyyy/mm/dd"
        void show() const;      // shows the date on the screen in format "yyyy/mm/dd"

        // b)
        bool isValid() const;
        bool isEqualTo(const Date &date);
        bool isNotEqualTo(const Date &date);
        bool isAfter(const Date &date);
        bool isBefore(const Date &date);

    private:
        // a)
        unsigned int year;
        unsigned int month;
        unsigned int day;

        // b)
        bool valid;
};