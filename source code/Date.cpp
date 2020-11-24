#include <iostream>
#include <string>
#include <iomanip> //to add leading zeroes

using namespace std;

#include "Date.h"

Date::Date() {
    this -> d = 1;
    this -> m = 1;
    this -> y = 2019;
}

//set day, month and year
Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    this->d = day;
    this->m = month;
    this->y = year;

    bool c = true;

    //check if day, month or year is out of range:
    if (day < 1 || day > 31) {
        cout << "Day must be 1-31!" << endl;
        c = false;
        if (c == false) {
            exit(0);
        }
    }

    if (month < 1 || month > 12) {
        cout << "Month must be 1-12!" << endl;
        c = false;
        if (c == false) {
            exit(0);
        }
    }

    if (year < 1000 || year > 9999) {
        cout << "Year must be 1000-9999!" << endl;
        c = false;
        if (c == false) {
            exit(0);
        }
    }

    //check if day is out of range for February of leap year:
    if (m == 2 && isLeapYear())
        day <= 29; //if February is in a leap year days will be 29
    else
        day <= 28; //else days are 28

    //set a maximum of 30 days for September, April, November and June:
    if (m == 9 || m == 4 || m == 11 || m == 6)
        day <= 30;
}

bool Date::isLeapYear() const
{
    if (y % 400 == 0 ||
        (y % 100 != 0 && y % 4 == 0))
        return true; // a leap year
    else
        return false; // not a leap year
}

bool Date::operator<(const Date& other) const {
    if (d < other.d)
        return true;
    else if (m < other.m)
        return true;
    else if (y < other.y)
        return true;
    else
        return false;
}

bool Date::operator>(const Date& other) const {
    if (d > other.d)
        return true;
    else if (m > other.m)
        return true;
    else if (y > other.y)
        return true;
    else
        return false;
}

Date::operator string() const {
    string monthName[13] = { "", "January", "February",
        "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December" };
    string s = monthName[m] + " " + to_string(d) + ", " + to_string(y);
    /*string s = to_string(d)
        + "/" + to_string(m)
        + "/" + to_string(y);*/
    return s;
}

ostream& operator<<(ostream& o, const Date& d) {
    o << setw(2) << setfill('0') << d.d << "/" << setw(2) << setfill('0') << d.m << "/" << d.y;
    /*static string monthName[13] = { "", "January", "February",
        "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December" };
    o << monthName[d.m] << " " << d.d << ", " << d.y;*/
    return o;
}

