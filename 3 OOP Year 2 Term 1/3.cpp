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

class PhanSo {
private:
    int tuSo, mauSo;

public:
    PhanSo rutGon();
    void nhap();
    void xuat();
};

void PhanSo::nhap()
{
    cout << "Nhap tu so ";
    cin >> this->tuSo;
    cout << "Nhap mau so ";
    cin >> this->mauSo;
}
void PhanSo::xuat()
{
    cout << this->tuSo << "/" << this->mauSo << " ";
}

PhanSo PhanSo::rutGon()
{
    int a, b;
    a = abs(this->tuSo);
    b = abs(this->mauSo);
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    this->tuSo /= a;
    this->mauSo /= b;

    return *this;
}
// cach dung thu 2: tra ve object hien tai
int main()
{
    PhanSo ps;

    ps.nhap();
    ps.rutGon();
    ps.xuat();

    return 0;
}