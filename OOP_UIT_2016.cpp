#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
class Time {
public:
    Time();
    Time(int hour);
    Time(int hour, int minutes);
    Time(int hour, int minutes, int seconds);
    void Giam();
    Time& operator--();
    Time operator--(int);
    friend ostream& operator <<(ostream& os, Time tg) {
        os << tg.hour << ":" << tg.minutes << ":" << tg.seconds << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Time& tg) {
        cout << "Input hour: ";
        is >> tg.hour;
        cout << "Input minutes: ";
        is >> tg.minutes;
        cout << "Input seconds: ";
        is >> tg.seconds;
        return is;
    }
private:
    int hour, minutes, seconds;
    bool hople(int, int, int);
};
bool Time::hople(int h, int m, int s) {
    return (h >= 0 && m >= 0 && s >= 0 && m <= 59 && s <= 59);
}
void Time::Giam() {
    if (hople(hour, minutes, seconds - 1)) {
        *this = Time(hour, minutes, seconds - 1);
    }
    else {
        if (hople(hour, minutes - 1, 59)) {
            *this = Time(hour, minutes - 1, 59);
        }
        else
            *this = Time(hour - 1, 59, 59);
    }
}
Time& Time::operator--() {
    Time tmp(hour, minutes, seconds);
    Giam();
    return tmp;
}
Time::Time() {
    hour = 0;
    minutes = 0;
    seconds = 0;
}
Time::Time(int hour) {
    this->hour = hour;
    minutes = 0;
    seconds = 0;
}
Time::Time(int hour, int minutes) {
    this->hour = hour;
    this->minutes = minutes;
    seconds = 0;
}
Time::Time(int hour, int minutes, int seconds) {
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
}

class ThanhPhan {
private:
    string text;
    int mauText;
    int mauNen;
public:
    ThanhPhan();
    virtual ~ThanhPhan();
    virtual void Nhap();
    virtual int getMauNen();
    virtual int getMauText();
};

class Label :public ThanhPhan {
public:
    Label();
    ~Label();
    void Nhap();
};

ThanhPhan::ThanhPhan() {
    text = "";
    mauNen = 0;
    mauText = 0;
}
ThanhPhan::~ThanhPhan() {
}
void ThanhPhan::Nhap() {
    cout << "Chon mau bang so duoi day : \n";
    cout << "1. Red, 2. Orange, 3.Yellow, 4. Spring Green\n";
    cout << "5. Red, 6. Orange, 7.Yellow, 8. Spring Green\n";
    cout << "9. Red, 10. Orange, 11.Yellow, 12. Spring Green\n";
    cout << "Chon mau nen : ";
    cin >> mauNen;
    cout << "Chon mau text : ";
    cin >> mauText;
    cin.ignore();
    cout << "Nhap text : ";
    getline(cin, text);
}
int ThanhPhan::getMauNen() {
    return mauNen;
}
int ThanhPhan::getMauText() {
    return mauText;
}
Label::Label() {
}
Label::~Label() {
}
void Label::Nhap() {
    cout << "Nhap label: \n";
    ThanhPhan::Nhap();
}
class Button :public ThanhPhan {
public:
    Button();
    ~Button();
    void Nhap();
};

Button::Button() {}
Button::~Button() {}
Button::Nhap() {
    cout << "Nhap button: \n";
    cout << "Chon 1: Nhap button image\n Chon 2: Button text\n";
    int tl;
    cin >> tl;
    if (tl == 1)
    {
        cout << "Nhap button image: \n";
        cout << ".....Xog!!";
        text = "";
        mauNen = 0;
        mauText = 0;
    }
    else
    {
        cout << "Nhap button text: \n";
        ThanhPhan::nhap();
    }
}

bool isMauBoTuc(int x, int y) {
    return abs(x - y) == 6;
}
bool isMauTuongDuong(int x, int y, int z)// x y z tang dan
{
    int data[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,1,2 };
    return (data[x + 1] == y && data[x + 2 == z]);
}
int main() {
    return 0;
}