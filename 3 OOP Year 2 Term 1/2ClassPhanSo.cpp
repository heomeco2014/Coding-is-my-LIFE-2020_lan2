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
    int tu_so, mau_so;

public:
    PhanSo() {
        this->tu_so = 0;
        this->mau_so = 1;
    }
    PhanSo(int tu_so, int mau_so) : tu_so(tu_so), mau_so(mau_so) {
    }
    ~PhanSo();
    void set() {
        cout << "Nhap tu so ";
        cin >> this->tu_so;
        cout << "Nhap mau so ";
        cin >> this->mau_so;
    }
    void rutGonPhanSo(PhanSo &ps) {
        int a = ps.tu_so;
        int b = ps.mau_so;
        while (a != b) {
            if (a > b)
                a -= b;
            else
                b -= a;
        }
        ps.tu_so /= a;
        ps.mau_so /= a;
    }
    void get();
    PhanSo Cong(PhanSo ps1, PhanSo ps2);
    PhanSo Tru(PhanSo ps1, PhanSo ps2);
    PhanSo Nhan(PhanSo ps1, PhanSo ps2);
    PhanSo Chia(PhanSo ps1, PhanSo ps2);
};

// Cong Tru Nhan Chia
PhanSo PhanSo::Cong(PhanSo ps1, PhanSo ps2) {
    PhanSo sum;
    sum.tu_so = ps1.mau_so * ps2.tu_so + ps2.mau_so * ps1.tu_so;
    sum.mau_so = ps1.mau_so * ps2.mau_so;
    rutGonPhanSo(sum);
    return sum;
}
PhanSo PhanSo::Tru(PhanSo obj1, PhanSo obj2) {
    PhanSo obj3;
    obj3.tu_so = obj1.tu_so * obj2.mau_so - obj1.mau_so * obj2.tu_so;
    obj3.mau_so = obj1.mau_so * obj2.mau_so;
    return obj3;
}
PhanSo PhanSo::Nhan(PhanSo obj1, PhanSo obj2) {
    PhanSo obj3;
    obj3.tu_so = obj1.tu_so * obj2.tu_so;
    obj3.mau_so = obj1.mau_so * obj2.mau_so;
    return obj3;
}
PhanSo PhanSo::Chia(PhanSo obj1, PhanSo obj2) {
    PhanSo obj3;
    obj3.tu_so = obj1.tu_so * obj2.mau_so;
    obj3.mau_so = obj1.mau_so * obj2.tu_so;
    return obj3;
}
// End Cong Tru Nhan Chia

void PhanSo::get() {
    cout << this->tu_so << "/" << this->mau_so << endl;
}
PhanSo::~PhanSo() {
    this->tu_so = 0;
    this->mau_so = 1;
}

int main() {
    PhanSo phan_so_1(1, 2);
    PhanSo phan_so_2(3, 4);
    PhanSo sum, key;

    key = sum.Cong(phan_so_1, phan_so_2);
    key.get();
    key = sum.Tru(phan_so_1, phan_so_2);
    key.get();
    key = sum.Nhan(phan_so_1, phan_so_2);
    key.get();
    key = sum.Chia(phan_so_1, phan_so_2);
    key.get();

    return 0;
}