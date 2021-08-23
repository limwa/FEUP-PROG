#include <iostream>
#include <sstream>
#include "date.h"

// a)
Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->setDate(year, month, day);
}

Date::Date(string yyyymmdd) {
    istringstream stream(yyyymmdd);

    unsigned int year, month, day;
    char sep1, sep2;
    stream >> year >> sep1 >> month >> sep2 >> day;

    this->setDate(year, month, day);
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

void Date::setMonth(unsigned int month) {
    this->month = month;
}

void Date::setDay(unsigned int day) {
    this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    this->setYear(year);
    this->setMonth(month);
    this->setDay(day);
}

unsigned int Date::getYear() const {
    return this->year;
}

unsigned int Date::getMonth() const {
    return this->month;
}

unsigned int Date::getDay() const {
    return this->day;
}

string Date::getDate() const {
    ostringstream stream;   

    stream.fill('0');
    stream.width(4);

    stream << this->year;
    
    stream.width(1);
    stream << '/';

    stream.width(2);

    stream << this -> month;

    stream.width(1);
    stream << '/';

    stream.width(2);
    stream << this->day;

    return stream.str();
}

void Date::show() const {
    cout << this->getDate();
}

// b)
bool Date::isValid() const {
    return this->valid;
}

bool Date::isEqualTo(const Date &date) {
    return this->isValid() 
        && date.isValid()
        && this->year == date.getYear()
        && this->month == date.getMonth()
        && this->day == date.getDay();
}

bool Date::isNotEqualTo(const Date &date) {
    return !this->isEqualTo(date);
}

bool Date::isAfter(const Date &date) {
    return this->isValid() 
        && date.isValid() 
        && this->getDate() > date.getDate();
}

bool Date::isBefore(const Date &date) {
    return this->isValid()
        && date.isValid()
        && !this->isEqualTo(date)
        && !this->isAfter(date); 
}