#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

static int daysInEveryMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
private:
    int day, month, year;

public:
    Date() {
        day = 1;
        month = 1;
        year = 1;
    }
    Date(int day, int month, int year) {
        this->day = abs(day);
        this->month = abs(month);
        this->year = abs(year);
        if (this->month > 12) {
            this->year += (this->month / 12);
            this->month %= 12;
        }
    }

    Date(const int &day) {
        int leapDays = (day / 365) / 4;
        this->year = day / 365 + 1;
        if (day % 365 == 0) {
            this->year = day / 365;
            this->day = 1 + leapDays;
            this->month = 1;
        } else {
            int leftDays = (day % 365);
            int sum = 0;
            for (int i = 0; i < 12; i++) {
                if (leftDays - sum > 0) {
                    sum += daysInEveryMonths[i];
                }

                else if (leftDays - sum <= 0) {
                    this->month = i;
                    break;
                }
            }
            int nextMonth = this->month;
            if (nextMonth + 1 > 11)
                nextMonth = 0;
            this->day = (day % 365 - sum + daysInEveryMonths[nextMonth + 1]) + leapDays > 0 ? (day % 365 - sum + daysInEveryMonths[nextMonth + 1]) + leapDays : 1;
        }
    }
    Date operator+(const Date &secondDay) {
        Date today = *this;
        today.day += secondDay.day;
        today.month += secondDay.month;
        today.year += secondDay.year;
        if (today.month > 12) {
            today.year += (today.month) / 12;
            today.month = today.month % 12;
        }
        return today;
    }

    Date operator+(const int &days) {
        Date today;
        today.day = day;
        today.month = month;
        today.year = year;
        int newDay = today.day + days;
        do {
            switch (today.month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (newDay > 31) {
                    today.month++;
                    if (today.month == 13) {
                        today.month = 1;
                        today.year++;
                    }
                    newDay -= 31;
                } else {
                    today.day = newDay;
                    newDay = 0;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (newDay > 30) {
                    today.month++;
                    newDay -= 30;
                } else {
                    today.day = newDay;
                    newDay = 0;
                }
                break;
            case 2:
                if (today.year % 400 == 0 || (today.year % 4 == 0 && today.year % 100 != 0)) {
                    if (newDay > 29) {
                        today.month++;
                        newDay -= 29;
                    } else {
                        today.day = newDay;
                        newDay = 0;
                    }
                } else {
                    if (newDay > 28) {
                        today.month++;
                        newDay -= 28;
                    } else {
                        today.day = newDay;
                        newDay = 0;
                    }
                }
                break;
            }
        } while (newDay > 0);
        return today;
    }
    friend Date operator+(const int &days, Date &today) {
        int newDay = today.day + days;
        do {
            switch (today.month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (newDay > 31) {
                    today.month++;
                    if (today.month == 13) {
                        today.month = 1;
                        today.year++;
                    }
                    newDay -= 31;
                } else {
                    today.day = newDay;
                    newDay = 0;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (newDay > 30) {
                    today.month++;
                    newDay -= 30;
                } else {
                    today.day = newDay;
                    newDay = 0;
                }
                break;
            case 2:
                if (today.year % 400 == 0 || (today.year % 4 == 0 && today.year % 100 != 0)) {
                    if (newDay > 29) {
                        today.month++;
                        newDay -= 29;
                    } else {
                        today.day = newDay;
                        newDay = 0;
                    }
                } else {
                    if (newDay > 28) {
                        today.month++;
                        newDay -= 28;
                    } else {
                        today.day = newDay;
                        newDay = 0;
                    }
                }
                break;
            }
        } while (newDay > 0);
        return today;
    }
    Date operator-(const Date &day) {
        Date t = *this;
        t.year -= day.year;
        t.month -= day.month;
        if (t.month <= 0) {
            t.month += 12;
            t.year--;
        }
        t.day -= day.day;
        if (t.day <= 0)
            t.day = 1;
        return t;
    }
    friend Date operator-(const int &day, const Date &secondDay) {
        Date n(day);
        return n - secondDay;
    }
    void printDate() {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
};
int main() {
    Date n1;
    n1.printDate();
    Date n2(02, 10, 2014);
    n2.printDate();
    Date n3(-10, 16, 2000);
    n3.printDate();
    Date n4(1000);
    n4.printDate();
    Date n5 = n2 + n3;
    n5.printDate();
    Date n6 = n1 + 5000;
    n6.printDate();
    Date n7 = 1234 + n4;
    n7.printDate();
    Date n8 = 190 + n6 + n7;
    n8.printDate();
    Date n9 = n8 - n6;
    n9.printDate();



    return 0;
}