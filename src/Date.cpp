#include "../include/Date.h"

Date::Date(): d_{1}, m_{Month::jan}, y_{2023}{}

Date::Date(int y, Month m, int d): y_{y}, m_{m}, d_{d}{
    if(!is_valid()){
        throw Invalid{};
    }
}

int Date::year() const{
    return y_;
}

Month Date::month() const{
    return m_;
}

int Date::day() const{
    return d_;
}

bool Date::is_leap_year(){
    if(y_ % 4 == 0){
        if(y_ % 100 == 0){
            if(y_ % 400 == 0){
                return true;
            }else{
                return false;
            }
        }else{
            return true;
        }
    }else{
        return false;
    }
}

bool Date::is_valid(){
    if(y_ < 1800 || y_ > 2200){
        return false;
    }
    if(m_ == Month::nov || m_ == Month::apr || m_ == Month::jun || m_ == Month::sep){
        if(d_ < 1 || d_ > 30){
            return false;
        }
    }
    if(m_ == Month::feb){
        if(is_leap_year()){
            if(d_ < 1 || d_ > 29){
                return false;
            }
        }else{
            if(d_ < 1 || d_ > 28){
                return false;
            }
        }
    }
    if(d_ < 1 || d_ > 31){
        return false;
    }
    return true;
}

void Date::add_year(int n){
    if(y_ + n > 2200){
        throw Invalid{};
    }
    y_ += n;
}

void Date::add_month(int n){
    if(int(m_) + n > int(Month::dec)){
        m_ = Month((int(m_) + n) % int(Month::dec));
        add_year((int(m_) + n) / int(Month::dec));
    }else{
        m_ = Month(int(m_) + n);
    }
}

void Date::add_one_day(){
    if(m_ == Month::nov || m_ == Month::apr || m_ == Month::jun || m_ == Month::sep){
        if(d_ + 1 > 30){
            add_month(1);
            d_ = 1;
        }else{
            d_++;
        }
    }else if(m_ == Month::feb){
        if(is_leap_year()){
            if(d_ + 1 > 29){
                add_month(1);
                d_ = 1;
            }else{
                d_++;
            }
        }else{
            if(d_ + 1 > 28){
                add_month(1);
                d_ = 1;
            }else{
                d_++;
            }
        }
    }else if(m_ == Month::dec){
        if(d_ + 1 > 31){
            add_year(1);
            add_month(1);
            d_ = 1;
        }else{
            d_++;
        }
    }else{
        if(d_ + 1 > 31){
            add_month(1);
            d_ = 1;
        }else{
            d_++;
        }
    }
}

void Date::add_day(int n){
    for(int i = 0; i < n; i++){
        add_one_day();
    }
}

std::ostream& operator<<(std::ostream& os, const Date& d){
    return os << d.day() << "/" << int(d.month()) << "/" << d.year();
}

bool operator==(const Date& d1, const Date& d2){
    return d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year();
}

bool operator!=(const Date& d1, const Date& d2){
    return !(d1 == d2);
}

bool operator<(const Date& d1, const Date& d2){
    if(d1.year() < d2.year()){
        return true;
    }else if(d1.year() > d2.year()){
        return false;
    }else{
        if(d1.month() < d2.month()){
            return true;
        }else if(d1.month() < d2.month()){
            return false;
        }else{
            if(d1.day() < d2.day()){
                return true;
            }else{
                return false;
            }
        }
    }
}

bool operator>(const Date& d1, const Date& d2){
    return !(d1 < d2);
}

bool operator<=(const Date& d1, const Date& d2){
    return (d1 < d2) || (d1 == d2);
}

bool operator>=(const Date& d1, const Date& d2){
    return (d1 > d2) || (d1 == d2);
}

Date operator+(const Date& d1, const Date& d2){
    Date sum{d1.day(), d1.month(), d1.year()};
    sum.add_year(d2.year());
    sum.add_month(int(d2.month()));
    sum.add_day(d2.day());
    return sum;
}
