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
class PhanSo {
private:
    int tu, mau;
public:
    void rutGon() {
        int GCD = __gcd(tu, mau);
        tu /= GCD;
        mau /= GCD;
    }
    PhanSo() {
        tu = 0;
        mau = 1;
    }
    PhanSo(const int& tu, const int& mau = 1) {
        this->tu = tu;
        this->mau = mau;
        this->rutGon();
    }
    PhanSo operator+(const PhanSo& ps) {
        PhanSo p;
        p.tu = this->tu * ps.mau + this->mau * ps.tu;
        p.mau = this->mau * ps.mau;
        p.rutGon();
        return p;
    }
    PhanSo operator-(const PhanSo& ps) {
        PhanSo p;
        p.tu = this->tu * ps.mau - this->mau * ps.tu;
        p.mau = this->mau * ps.mau;
        p.rutGon();
        return p;
    }
    friend PhanSo operator+(const int& number, const PhanSo& ps) {
        PhanSo p;
        p.tu = number * ps.mau + ps.tu;
        p.mau = ps.mau;
        p.rutGon();
        return p;
    }
    friend PhanSo operator-(const int& number, const PhanSo& ps) {
        PhanSo p;
        p.tu = number * ps.mau - ps.tu;
        p.mau = ps.mau;
        p.rutGon();
        return p;
    }

    friend ostream& operator <<(ostream& os, const PhanSo& ps) {
        cout << ps.tu << "/" << ps.mau;
        return os;
    }
};
int main() {
    PhanSo ps;
    PhanSo ps1(200);
    PhanSo ps2(6, 8);
    PhanSo ps3 = ps1 + ps2;
    PhanSo ps4 = 150 + ps2;
    PhanSo ps5 = ps1 - ps2;
    PhanSo ps6 = 225 - ps2;
    cout << ps2 << endl;
    cout << ps << endl << ps1 << endl << ps2 << endl << ps3 << endl << ps4 << endl << ps5 << endl << ps6;
    return 0;
}