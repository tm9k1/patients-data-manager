#include "date.h"

#include <array>
#include <sstream>
#include <iomanip>

namespace {
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


bool isValidDate(const int day, const int month, const int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    std::array<int, 12> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[1] = 29; // February in a leap year
    }

    return day <= daysInMonth[month - 1];
}


}
namespace Types {

Date_C::Date_C() = default;

Date_C::Date_C(const int& day, const int& month, const int& year)
{
    if (isValidDate(day, month, year)) {
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
    int day, month, year;
    char delimiter;

    // parse "DD/MM/YYYY" into day , month, year
    ss >> day >> delimiter >> month >> delimiter >> year;

    if (isValidDate(day, month, year)) {
        _day = day;
        _month = month;
        _year = year;
    } else {
        throw std::runtime_error("Invalid Date provided.");
    }
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

} // namespace Types
