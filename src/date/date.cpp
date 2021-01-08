// date.cpp
// Implementation of the Date class

#include "date.h"

Date::Date(int day, Month month, int year):day_{day}, month_{month}, year_{year}
{
    if(year_ < 0) throw invalidDate_Year();
    if ( static_cast<int>(month_) < 1  ||  static_cast<int>(month_) > 12  ) throw invalidDate_Month();
    if((day_ <= 0)||(day_ > daysInMonth())) throw invalidDate_Day();
}
int Date::day() const
{
	return day_;
}

Month Date::month() const
{
    return month_;
}

int Date::year() const
{
	return year_;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (month_) {
		case Month::January:
		case Month::March:
		case Month::May:
		case Month::July:
		case Month::August:
		case Month::October:
		case Month::December:
			return 31;
		case Month::April:
		case Month::June:
		case Month::September:
		case Month::November:
			return 30;
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}
}

bool Date::operator==(const Date& rhs) const
{
// compare data members here
// return true for identical dates, false otherwise
   if((this->day() == rhs.day()) &&(this->month() == rhs.month()) && (this->year() == rhs.year()))
        return true;
   else return false;
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

