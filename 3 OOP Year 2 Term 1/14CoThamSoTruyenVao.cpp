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
private:
    int hour, min;

public:
    Time(){};
    Time(int hour, int minutes) : hour(hour), min(minutes) {}
    void inputTime(int &hour, int &min) {
        this->hour = hour;
        this->min = min;
    }
    void print() {
        cout << hour << ":" << min << endl;
    }

    Time Sum(Time first, Time second) {
        this->hour = first.hour + second.hour;
        this->min = first.min + second.min;
        if (first.min == 60 && second.min == 60) {
            this->hour += 2;
        } else if (this->min > 60) {
            this->hour++;
        }
        this->min %= 60;

        return *this;
    }
};
int main() {
    Time fTime(2, 40);
    Time sTime(2, 60);
    Time Sum;

    Sum.Sum(fTime, sTime);
    Sum.print();
    return 0;
}