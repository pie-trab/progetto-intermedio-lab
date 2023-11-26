#include <iostream>
#include "Month.h"

class Date{
	private:
		int y_;
		Month m_;
		int d_;

		bool is_valid(); // checks if the date is a valid date
        bool is_leap_year(); //checks if the year is a leap year
        void add_one_day(); //adds one day to the current date time
		
        class Invalid{};

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

