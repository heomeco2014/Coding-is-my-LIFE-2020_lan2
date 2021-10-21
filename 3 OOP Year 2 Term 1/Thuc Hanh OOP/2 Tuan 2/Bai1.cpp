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
    Ngay() {
        ngay = 1;
        thang = 1;
        nam = 1;
    }
    Ngay(int ngay, int thang, int nam) {
        this->ngay = abs(ngay);
        this->thang = abs(thang);
        this->nam = abs(nam);
        if (this->thang > 12) {
            this->nam += (this->thang -= 12) / 12 + 1;
        }
    }
    Ngay(int ngay) {
        this->nam = ngay / 365 + 1;
        this->thang = (ngay % 365) / 31 + 1;
        this->ngay = (ngay % 365 % 31);
    }
    Ngay operator+(const Ngay ngaySau) {
        Ngay homnay = *this;
        homnay.ngay += ngaySau.ngay;
        homnay.thang += ngaySau.thang;
        homnay.nam += ngaySau.nam;
        if (homnay.ngay > 31) {
            homnay.ngay -= 31;
            homnay.thang += (homnay.ngay + 1) / 31;
        }
        if (homnay.thang > 12) {
            homnay.thang -= 12;
            homnay.nam += (homnay.thang + 12) / 12;
        }
        return homnay;
    }
    Ngay operator-(const Ngay ngaySau) {
        Ngay homnay = *this;
        homnay.ngay -= ngaySau.ngay;
        homnay.thang -= ngaySau.thang;
        homnay.nam -= ngaySau.nam;
        if (homnay.ngay < 0) {
            homnay.ngay += 31;
            homnay.thang -= 1;
            if (homnay.thang < 0) {
                homnay.thang -= 12;
                homnay.nam += (homnay.thang + 12) / 12;
            }
        }
        return homnay;
    }
    void printNgay() {
        cout << this->ngay << "/" << this->thang << "/" << this->nam << endl;
    }
};
int main() {
    Ngay n1;
    n1.printNgay();
    Ngay n2(02, 10, 2014);
    n2.printNgay();
    Ngay n3(-10, 16, 2000);
    n3.printNgay();
    Ngay n4(1000);
    n4.printNgay();
    Ngay n5 = n2 + n3;
    n5.printNgay();
    Ngay n6 = n1 + 5000;
    n6.printNgay();
    return 0;
}