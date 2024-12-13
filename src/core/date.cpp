#include "date.h"
#include <array>

namespace {

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

}

Date::Date() = default;
Date::Date(const int& day, const int& month, const int& year)
{
    if (Date::isValidDate()) {
        _day = day;
        _month = month;
        _year = year;
    } else {
        throw std::runtime_error("Invalid Date provided.");
    }
}

bool Date::isValidDate() {
    if (_year < 1 || _month < 1 || _month > 12 || _day < 1) {
        return false;
    }

    std::array<int, 12> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(_year)) {
        daysInMonth[1] = 29; // February in a leap year
    }

    return _day <= daysInMonth[_month - 1];
}

void Date::SetDate(const Date& date)
{
    _day = date.GetDay();
    _month = date.GetMonth();
    _year = date.GetYear();
}

void Date::PrettyPrint() const
{
    std::cout << _day << "/" << _month << "/" << _year;
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
    date.PrettyPrint();
    return stream;

}