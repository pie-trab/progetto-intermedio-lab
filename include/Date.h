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

    bool is_valid();      // checks if the date is a valid date
    bool is_leap_year();  // checks if the year is a leap year

public:
    Date();
    Date(int, Month, int);

    int year() const;
    Month month() const;
    int day() const;
};

std::ostream& operator<<(std::ostream&, const Date&);
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator<(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator>=(const Date&, const Date&);
#endif