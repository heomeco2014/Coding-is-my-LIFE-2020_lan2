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

class SoPhuc
{
private:
    int thuc, ao;
    int SoLuong;
    static int staticSoLuong;
public:
    SoPhuc() :thuc(0), ao(0) {
        SoLuong++;
        staticSoLuong++;
    }
    SoPhuc(const int& thuc, const int& ao = 0) {
        this->thuc = thuc;
        this->ao = ao;
        SoLuong++;
        staticSoLuong++;
    }
    SoPhuc(const SoPhuc& sp) {
        thuc = sp.thuc;
        ao = sp.ao;
        SoLuong++;
        staticSoLuong++;
    }
    ~SoPhuc() {
        SoLuong--;
        staticSoLuong--;
    }
    SoPhuc operator+(const SoPhuc& sp) {
        SoPhuc sp2;
        sp2.thuc = this->thuc + sp.thuc;
        sp2.ao = this->ao + sp.ao;
        return sp2;
    }
    int SoLuongSp() {
        return SoLuong;
    }
    static int StaticSoLuongSoPhuc() {
        return staticSoLuong;
    }
};
int SoPhuc::staticSoLuong = 0;

int main() {
    SoPhuc sp1;
    SoPhuc sp2(5, 10);
    SoPhuc sp3(sp1);
    SoPhuc sp4 = sp2 + sp1;
    //cout << SoPhuc::SSoLuongSP() << endl;

    SoPhuc sp5;
    SoPhuc sp6 = sp2 + sp4;

    cout << sp4.SoLuongSp() << endl; //???
    cout << SoPhuc::StaticSoLuongSoPhuc() << endl; //4
    return 0;
}