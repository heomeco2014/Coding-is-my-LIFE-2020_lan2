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
    PhanSo() {
    }
    PhanSo(int tu_so, int mau_so) : tuSo(tu_so), mauSo(mau_so) {}
    ~PhanSo() { cout << "Remove phan so " << tuSo << "/" << mauSo; }
    PhanSo rutGon();
    void prinPhanso();
    void xuat();
};

void PhanSo::xuat() {
    cout << this->tuSo << "/" << this->mauSo << endl;
}
PhanSo PhanSo::rutGon() {
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
    this->mauSo /= a;
}
int main() {
    PhanSo *phan_so = new PhanSo(1, 2);
    phan_so->xuat();
    return 0;
}