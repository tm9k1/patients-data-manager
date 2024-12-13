#include "date.h"

#include <array>
#include <sstream>
#include <iomanip>

namespace {

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

}

Date_C::Date_C() = default;

Date_C::Date_C(const int& day, const int& month, const int& year)
{
    if (Date_C::isValidDate()) {
        _day = day;
        _month = month;
        _year = year;
    } else {
        throw std::runtime_error("Invalid Date provided.");
    }
}

Date_C::Date_C(const std::string& date)
{
    std::stringstream ss(date);
    char delimiter;

    ss >> _day >> delimiter >> _month >> delimiter >> _year;
}

bool Date_C::isValidDate() {
    if (_year < 1 || _month < 1 || _month > 12 || _day < 1) {
        return false;
    }

    std::array<int, 12> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(_year)) {
        daysInMonth[1] = 29; // February in a leap year
    }

    return _day <= daysInMonth[_month - 1];
}

void Date_C::SetDate(const Date_C& date)
{
    _day = date.GetDay();
    _month = date.GetMonth();
    _year = date.GetYear();
}

std::string Date_C::ToString() const
{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << _day << '/'
        << std::setw(2) << std::setfill('0') << _month << '/'
        << _year;
    return ss.str();
}

std::ostream& operator<<(std::ostream& stream, const Date_C& date)
{
    std::cout << date.ToString();
    return stream;

}