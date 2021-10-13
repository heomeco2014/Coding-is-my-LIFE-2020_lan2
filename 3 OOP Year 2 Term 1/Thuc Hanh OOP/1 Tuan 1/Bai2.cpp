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

class ThoiGian {
private:
    int hour = 0, min = 0, sec = 0;

public:
    void xuat()
    {
        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec << endl;
    }
    ThoiGian()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }
    ThoiGian(int giay)
    {
        sec = giay % 60;
        min = giay / 60;
        hour = giay / 3600;
    }

    ThoiGian(int phut, int giay)
    {
        sec = giay;
        min = phut % 60;
    }
    ThoiGian(int gio, int phut, int giay)
    {
        if (giay < 0)
            sec = 0;
        min = phut % 60;
        hour = (phut - phut % 60) / 60 + gio;
    }
};
int main()
{
    ThoiGian tg1;
    tg1.xuat();

    ThoiGian tg2(1212);
    tg2.xuat();

    ThoiGian tg3(125, 45);
    tg3.xuat();

    ThoiGian tg4(12, 239, -78);
    tg4.xuat();
    return 0;
}