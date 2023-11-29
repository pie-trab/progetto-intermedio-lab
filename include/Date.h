#ifndef DATE_H
#define DATE_H

#include "Month.h"

#include <iostream>

const int MIN_YEAR = 1;
const int MAX_YEAR = 3000;

class Date
{
private:
    int _y;
    Month _m;
    int _d;

    bool is_valid();        // checks if the date is a valid date
    bool is_leap_year();    // checks if the year is a leap year
    void add_one_day();     // adds one day to the current date time

public:
    Date();
    Date(int, Month, int);

    int year() const;       // returns the year
    Month month() const;    // returns the month
    int day() const;        // returns the day

    void add_day(int);      // increments the current date of a specified number of days
    void add_month(int);    // increments the current date of a specified number of months
    void add_year(int);     // increments the current date of a specified number of years
};

std::ostream& operator<<(std::ostream&, const Date&);
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator<(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator>=(const Date&, const Date&);
#endif