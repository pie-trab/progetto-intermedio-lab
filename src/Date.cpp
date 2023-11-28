#include "../include/Date.h"

Date::Date() : _d{1}, _m{Month::jan},_y{2023} {}

Date::Date(int y, Month m, int d) :_y{y}, _m{m}, _d{d}
{
    if (!is_valid()) {
        throw Invalid{};
    }
}

int Date::year() const
{
    return _y;
}

Month Date::month() const
{
    return _m;
}

int Date::day() const
{
    return _d;
}

bool Date::is_leap_year()
{
    return (((_y % 4 == 0) && (_y % 100 != 0)) || (_y % 400 == 0));
}

bool Date::is_valid()
{
    if (_y < 1800 ||_y > 2200) {
        return false;
    }
    if (_m == Month::nov || _m == Month::apr || _m == Month::jun || _m == Month::sep) {
        if (_d < 1 || _d > 30) {
            return false;
        }
    }
    if (_m == Month::feb) {
        if (is_leap_year()) {
            if (_d < 1 || _d > 29) {
                return false;
            }
        } else {
            if (_d < 1 || _d > 28) {
                return false;
            }
        }
    }

    if (_d < 1 || _d > 31) {
        return false;
    }

    return true;
}

void Date::add_year(int n)
{
    if (_y + n > 2200) {
        throw Invalid{};
    }
   _y += n;
}

void Date::add_month(int n)
{
    if (int(_m) + n > int(Month::dec)) {
        _m = Month((int(_m) + n) % int(Month::dec));
        add_year((int(_m) + n) / int(Month::dec));
    } else {
        _m = Month(int(_m) + n);
    }
}

void Date::add_one_day()
{
    if (_m == Month::nov || _m == Month::apr || _m == Month::jun || _m == Month::sep) {
        if (_d + 1 > 30) {
            add_month(1);
            _d= 1;
        } else {
            _d++;
        }
    } else if (_m == Month::feb) {
        if (is_leap_year()) {
            if (_d+ 1 > 29) {
                add_month(1);
                _d= 1;
            } else {
                _d++;
            }
        } else {
            if (_d + 1 > 28) {
                add_month(1);
                _d = 1;
            } else {
                _d++;
            }
        }
    } else if (_m == Month::dec) {
        if (_d + 1 > 31) {
            add_year(1);
            add_month(1);
            _d = 1;
        } else {
            _d++;
        }
    } else {
        if (_d + 1 > 31) {
            add_month(1);
            _d = 1;
        } else {
            _d++;
        }
    }
}

void Date::add_day(int n)
{
    for (int i = 0; i < n; i++) {
        add_one_day();
    }
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << d.day() << "/" << int(d.month()) << "/" << d.year();
}

bool operator==(const Date& d1, const Date& d2)
{
    return d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year();
}

bool operator!=(const Date& d1, const Date& d2)
{
    return !(d1 == d2);
}

bool operator<(const Date& d1, const Date& d2)
{
    if (d1.year() < d2.year()) {
        return true;
    } else if (d1.year() > d2.year()) {
        return false;
    } else {
        if (d1.month() < d2.month()) {
            return true;
        } else if (d1.month() < d2.month()) {
            return false;
        } else {
            if (d1.day() < d2.day()) {
                return true;
            } else {
                return false;
            }
        }
    }
}

bool operator>(const Date& d1, const Date& d2)
{
    return !(d1 < d2);
}

bool operator<=(const Date& d1, const Date& d2)
{
    return (d1 < d2) || (d1 == d2);
}

bool operator>=(const Date& d1, const Date& d2)
{
    return (d1 > d2) || (d1 == d2);
}

Date operator+(const Date& d1, const Date& d2)
{
    Date sum{d1.day(), d1.month(), d1.year()};
    sum.add_year(d2.year());
    sum.add_month(int(d2.month()));
    sum.add_day(d2.day());
    return sum;
}
