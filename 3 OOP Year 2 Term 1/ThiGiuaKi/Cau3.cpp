#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo() {
        tu = 0;
        mau = 1;
    }
    PhanSo(int i_tu, int i_mau = 1) {
        tu = i_tu;
        mau = i_mau;
    }

    void simplify() {
        int UCLN = gcd(std::abs(this->tu), std::abs(this->mau));
        this->tu /= UCLN;
        this->mau /= UCLN;
        if (this->tu < 0 && this->mau < 0) {
            this->tu = std::abs(this->tu);
            this->mau = std::abs(this->mau);
        }
        else if (this->tu > 0 && this->mau < 0) {
            this->tu *= -1;
            this->mau = std::abs(this->mau);
        }
    }

    friend PhanSo operator+(const PhanSo& other, const PhanSo& other2) {
        PhanSo d;
        d.tu = other.tu * other2.mau + other.mau * other2.tu;
        d.mau = other.mau * other2.mau;
        d.simplify();
        return d;
    }
    friend PhanSo operator+(const int& soNguyen, const PhanSo& ps) {
        PhanSo d;
        d.tu = soNguyen * ps.mau + ps.tu;
        d.mau = ps.mau;
        d.simplify();
        return d;
    }
    friend PhanSo operator-(const PhanSo& other, const PhanSo& other2) {
        PhanSo d;
        d.tu = other.tu * other2.mau - other.mau * other2.tu;
        d.mau = other.mau * other2.mau;
        d.simplify();
        return d;
    }
    friend PhanSo operator-(const int& soNguyen, const PhanSo& ps) {
        PhanSo d;
        d.tu = soNguyen * ps.mau - ps.tu;
        d.mau = ps.mau;
        d.simplify();
        return d;
    }
    friend ostream& operator << (ostream& os, const PhanSo& ps) {
        os << ps.tu << "/" << ps.mau;
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
    cout << ps2 <<endl;
    // cout <<ps << endl<< ps1 << endl << ps2 << endl << ps3 << endl << ps4 <<  endl << ps5 << endl << ps6;
    return 0;
}