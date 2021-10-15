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

class Ngay {
private:
    int ngay, thang, nam;

public:
    Ngay()
    {
        ngay = 1;
        thang = 1;
        nam = 1;
    }

    Ngay( int day,  int month,  int year)
    {
        if (day > 0 && day < 32)
            ngay = day;
        else
            ngay = 1;
        if (month > 0 && month <= 12)
            thang = month;
        else
            thang = 12;
        if (year > 0)
            nam = year;
        else
            nam = 2000;
    }
    Ngay(int day)
    {
        nam = day / 365;
        thang = (day - 365*nam)/30;
        nam++;
       
    }
    void xuat()
    {
        cout << this->ngay << "/" << this->thang << "/" << this->nam << endl;
    }
};
int main()
{
    Ngay n1;
    n1.xuat();
    Ngay n2(02, 10, 2014);
    n2.xuat();
    Ngay n3(-10, 16, 2000);
    n3.xuat();
    Ngay n4(1000);
    n4.xuat();
    return 0;
}