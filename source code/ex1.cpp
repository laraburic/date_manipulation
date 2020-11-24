#include <iostream>
#include <string>

using namespace std;

#include "Date.h"

//if implemented from Date it would not exit on invalid input and go ahead displaying info
bool validDate (int d, int m, int y)
{
    //check if day, month or year is out of range:
    if (d < 1 || d > 31)
        return false;

    if (m < 1 || m > 12)
        return false;

    if (y < 1000 || y > 9999)
        return false;

    //check if day is out of range for February of leap year:
    if (m == 2 && (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)))
        return (d <= 29); //if February is in a leap year days will be 29
    else
        return (d <= 28); //else days are 28

    //set a maximum of 30 days for September, April, November and June:
    if (m == 9 || m == 4 || m == 11 || m == 6)
        return (d <= 30);

    return true;
}

int main()
{
    string name;

    //values storing info about the birthday:
    int birthDay;
    int birthMonth;
    int birthYear;

    //values storing info about the current day:
    int currentMonth;
    int currentDay;
    int currentYear;

    //implementations from Date:
    Date date1, date2;
    
    //an array holding the number of days for each month
    //starting from 0 so we can access January with index 1
    int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    //asking user for input:
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter birthdate in format dd mm yyyy: ";
    cin >> birthDay >> birthMonth >> birthYear;
    date1 = Date(birthDay, birthMonth, birthYear);

    cout << "Enter current date in format dd mm yyyyy: ";
    cin >> currentDay >> currentMonth >> currentYear;
    date2 = Date(currentDay, currentMonth, currentYear);

    //if implemented from Date it would not exit on invalid input and go ahead displaying info
    //checking to see if input dates are valid:
    if (validDate(currentDay, currentMonth, currentYear) == false || validDate(birthDay, birthMonth, birthYear) == false)
    {
        cout << "This date is not valid!" << endl;
        exit(0);
    }

    if (birthDay > currentDay) {
        currentDay += month[birthMonth - 1];
        currentMonth = currentMonth - 1;
    }

    if (birthMonth > currentMonth) {
        currentYear = currentYear - 1;
        currentMonth = currentMonth + 12;
    }

    //output data and calculate age:
    if (date2 > date1) { //uses operator from Date
        cout << "Name: " << name << endl;
        cout << "Birthday: " << string(date1) << ", which was " << currentYear - birthYear << " years, "
            << currentMonth - birthMonth << " months and " << currentDay - birthDay << " days ago. ";
        cout << "(End date considered: " << date2 << ")\n";

        //check if the birthDate is a leap year:
        if (date1.isLeapYear() == true)
            cout << "Born in a leap year." << endl;
        else
            cout << "Not born in a leap year." << endl;
    }

    else if (date1 > date2)
    {
        cout << "Error. Birth year is greater than current year." << endl;
        exit(0);
    }
}
