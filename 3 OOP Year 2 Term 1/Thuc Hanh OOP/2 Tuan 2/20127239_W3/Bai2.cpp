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

class Time {
public:
    Time();
    Time(int sec);
    Time(int sec, int min);
    Time(int hour, int min, int sec);
    Time operator+(const Time &);
    friend Time operator+(const int &, const Time &);
    Time operator-(const Time &);
    friend Time operator-(const int &, const Time &);
    bool operator<=(const Time &);
    friend bool operator<=(const int &, const Time &);
    ~Time(){};
    friend ostream &operator<<(ostream &, const Time &);

private:
    int hour, min, sec;
};

Time::Time() {
    hour = 0;
    min = 0;
    sec = 0;
}
Time::Time(int sec) {
    hour = sec / 3600;
    hour %= 24;
    min = sec / 60;
    min %= 60;
    this->sec = sec % 60;
}
Time::Time(int min, int sec) {
    min = abs(min);
    sec = abs(sec);
    int hour = 0;
    if (sec >= 60) {
        min += sec / 60;
        sec %= 60;
    }
    if (min >= 60) {
        hour += min / 60;
        min %= 60;
    }
    this->sec = sec;
    this->min = min;
    this->hour = hour;
}
Time::Time(int hour, int min, int sec) {
    hour = abs(hour);
    min = abs(min);
    sec = abs(sec);
    if (sec >= 60) {
        min += sec / 60;
        sec %= 60;
    }
    if (min >= 60) {
        hour += min / 60;
        min %= 60;
    }
    this->sec = sec;
    this->min = min;
    this->hour = hour;
}
Time Time::operator+(const Time &thisTime) {
    Time res(thisTime.hour + hour, thisTime.min + min, thisTime.sec + sec);
    return res;
}
Time operator+(const int &second, const Time &thisTime) {
   Time _time(second);
   return _time + thisTime;
}
Time Time::operator-(const Time &thisTime) {
    Time tmp = *this;
    Time res;
    if (tmp.sec < thisTime.sec) {
        tmp.sec += 60;
        if (tmp.min == 0) {
            tmp.min = 59;
            tmp.hour--;
        } else {
            tmp.min--;
        }
        res.sec = tmp.sec - thisTime.sec;
        res.min = tmp.min - thisTime.min;
        res.hour = tmp.hour - thisTime.hour;
    } else {
        res.sec = tmp.sec - thisTime.sec;
        res.min = tmp.min - thisTime.min;
        res.hour = tmp.hour - thisTime.hour;
    }
    return res;
}
Time operator-(const int &second, const Time &thisTime) {
   Time _time(second);
	return _time - thisTime;
}
bool Time::operator<=(const Time &thisTime) {
    if (hour < thisTime.hour) {
        return true;
    } else if (hour == thisTime.hour) {
        if (min < thisTime.min) {
            return true;
        } else if (min == thisTime.min) {
            if (sec <= thisTime.sec) {
                return true;
            }
        }
    }
    return false;
}
bool operator<=(const int &second, const Time &thisTime) {
    int sec = thisTime.sec + thisTime.min * 60 + thisTime.hour * 3600;
    if (second <= sec) {
        return true;
    }
    return false;
}
ostream &operator<<(ostream &os, const Time &thisTime) {
    os << setw(2) << setfill('0') << abs(thisTime.hour) << ":"
       << setw(2) << setfill('0') << abs(thisTime.min) << ":"
       << setw(2) << setfill('0') << abs(thisTime.sec);
    return os;
}

int main() {
    Time tg1;
    Time tg2(1212);
    Time tg3(125, 45);
    Time tg4(12, 239, -78);
    Time tg5 = tg2 + tg3;
    Time tg6 = 5000 + tg2;
    Time tg7 = tg4 - tg6;
    Time tg8 = 12300 - tg4;
    Time tg9, tg10;
    if (tg8 <= tg3) {
        tg9 = tg1 + tg2 + 36000;
    }
    if (12345 <= tg5) {
        tg10 = tg5 + 12345;
    }

    cout << tg1 << endl
         << tg2 << endl
         << tg3 << endl
         << tg4 << endl;
    cout << tg5 << endl
         << tg6 << endl
         << tg7 << endl
         << tg8 << endl;
    cout << tg9 << endl
         << tg10 << endl;
    return 0;
}