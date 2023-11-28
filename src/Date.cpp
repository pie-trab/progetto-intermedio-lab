#include "../include/Date.h"

/**
 * @brief Construct a new Date:: Date object
 *
 */
Date::Date() : _d{1}, _m{Month::jan}, _y{2023} {}

/**
 * @brief Construct a new Date:: Date object
 *
 * @param y year
 * @param m month
 * @param d day
 */
Date::Date(int y, Month m, int d) : _y{y}, _m{m}, _d{d}
{
    if (!is_valid()) {
        throw Invalid{};
    }
}

/**
 * @brief Get year
 *
 * @return int year
 */
int Date::year() const
{
    return _y;
}

/**
 * @brief Get month
 *
 * @return Month month
 */
Month Date::month() const
{
    return _m;
}

/**
 * @brief Get day
 *
 * @return int day
 */
int Date::day() const
{
    return _d;
}

/**
 * @brief Checks if is a leap year
 *
 * @return true leap year
 * @return false not a leap year
 */
bool Date::is_leap_year()
{
    return (((_y % 4 == 0) && (_y % 100 != 0)) || (_y % 400 == 0));
}

/**
 * @brief Checks if is a valid date
 *
 * @return true valid date
 * @return false invalid date
 */
bool Date::is_valid()
{
    if (_y < 1800 || _y > 2200) {
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

/**
 * @brief Adds n years
 *
 * @param n years to add
 */
void Date::add_year(int n)
{
    if (_y + n > 2200) {
        throw Invalid{};
    }
    _y += n;
}

/**
 * @brief Adds n months
 *
 * @param n months to add
 */
void Date::add_month(int n)
{
    if (int(_m) + n > int(Month::dec)) {
        _m = Month((int(_m) + n) % int(Month::dec));
        add_year((int(_m) + n) / int(Month::dec));
    } else {
        _m = Month(int(_m) + n);
    }
}

/**
 * @brief Adds one day
 *
 */
void Date::add_one_day()
{
    if (_m == Month::nov || _m == Month::apr || _m == Month::jun || _m == Month::sep) {
        if (_d + 1 > 30) {
            add_month(1);
            _d = 1;
        } else {
            _d++;
        }
    } else if (_m == Month::feb) {
        if (is_leap_year()) {
            if (_d + 1 > 29) {
                add_month(1);
                _d = 1;
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

/**
 * @brief Add n day
 *
 * @param n days to add
 */
void Date::add_day(int n)
{
    for (int i = 0; i < n; i++) {
        add_one_day();
    }
}

/**
 * @brief Ostream operator overload
 *
 * @param os os stream
 * @param d date to send to the stream
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Date& d)
{
    return os << d.day() << "/" << int(d.month()) << "/" << d.year() << "\n";
}

/**
 * @brief
 *
 * @param d1
 * @param d2
 * @return true
 * @return false
 */
bool operator==(const Date& d1, const Date& d2)
{
    return d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year();
}

/**
 * @brief Equals operator overload
 *
 * @param d1 first date to compare
 * @param d2 second date to compare
 * @return true equals
 * @return false not equals
 */
bool operator!=(const Date& d1, const Date& d2)
{
    return !(d1 == d2);
}

/**
 * @brief Less than operator overload
 *
 * @param d1 first date to compare
 * @param d2 second date to compare
 * @return true d1 < d2
 * @return false d1 >= d2
 */
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

/**
 * @brief Greater than operator overload
 *
 * @param d1 first date to compare
 * @param d2 second date to compare
 * @return true d1 > d2
 * @return false d1 <= d2
 */
bool operator>(const Date& d1, const Date& d2)
{
    return !(d1 < d2);
}

/**
 * @brief Less equal than operator overload
 *
 * @param d1 first date to compare
 * @param d2 second date to compare
 * @return true d1 <= d2
 * @return false d1 > d2
 */
bool operator<=(const Date& d1, const Date& d2)
{
    return (d1 < d2) || (d1 == d2);
}

/**
 * @brief Greater equal than operator overload
 *
 * @param d1 first date to compare
 * @param d2 second date to compare
 * @return true d1 >= d2
 * @return false d1 < d2
 */
bool operator>=(const Date& d1, const Date& d2)
{
    return (d1 > d2) || (d1 == d2);
}

/**
 * @brief Sum operator overload
 *
 * @param d1 first date to sum
 * @param d2 second date to sum
 * @return Date
 */
Date operator+(const Date& d1, const Date& d2)
{
    Date sum{d1.day(), d1.month(), d1.year()};
    sum.add_year(d2.year());
    sum.add_month(int(d2.month()));
    sum.add_day(d2.day());
    return sum;
}
