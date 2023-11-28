#ifndef DATE_H
#define DATE_H

#include "Month.h"

#include <iostream>

class Date
{
private:
    int _y;
    Month _m;
    int _d;

    bool is_valid();      // checks if the date is a valid date
    bool is_leap_year();  // checks if the year is a leap year
    void add_one_day();   // adds one day to the current date time

    class Invalid
    {
    };

public:
    Date();
    Date(int, Month, int);

    int year() const;
    Month month() const;
    int day() const;

    void add_day(int);
    void add_month(int);
    void add_year(int);
};

std::ostream& operator<<(std::ostream&, const Date&);
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator<(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator>=(const Date&, const Date&);
Date operator+(const Date&, const Date&);
#endif