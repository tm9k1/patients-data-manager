#pragma once

#include <iostream>
/* DATE
//
// Basic Date Data Structure that can hold a date and allow convenient I/O over it
//
*/
class Date
{

public:
    // ctors
    Date();
    Date(const int& day, const int& month, const int& year);

    // getters
    int GetDay()    const {return _day;}
    int GetMonth()  const {return _month;}
    int GetYear()   const {return _year;}

    // setter is Date-only to allow validation throgh construction
    void SetDate(const Date& date);

    friend std::ostream& operator<<(std::ostream&, const Date&);

private: // helpers
    bool isValidDate();
    void PrettyPrint() const;

private:

    u_int16_t _day = 1;
    u_int16_t _month = 1;
    u_int64_t _year = 1970; // supports up to UINT64_MAX
};
