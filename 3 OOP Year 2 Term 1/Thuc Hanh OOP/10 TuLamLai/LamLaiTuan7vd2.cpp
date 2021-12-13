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

class HinhHocPhang {
public:
    HinhHocPhang() {};
    virtual double TinhDienTich() {
        return 0;
    }
};

class HinhChuNhat :public HinhHocPhang {
private:
    double chieuDai, chieuRong;
public:
    HinhChuNhat() :chieuDai(0), chieuRong(0) {}
    HinhChuNhat(const double& cd, const double& cr) {
        chieuDai = (cd == 0) ? 1 : abs(cd);
        chieuRong = (cr == 0) ? 1 : abs(cr);
    }
    virtual  double TinhDienTich() {
        return chieuDai * chieuRong;
    }
};
#define PI 3.14159

class HinhTron :HinhHocPhang {
private:
    double banKinh;
public:
    HinhTron() :banKinh(0) {}
    HinhTron(const double& bk) {
        banKinh = bk;
    }
    virtual double TinhDienTich() {
        return banKinh * banKinh * PI;
    }
};

int main() {
    HinhHocPhang* hhp = new HinhHocPhang();
    HinhChuNhat* hcn = new HinhChuNhat(34, 56.8);
    HinhTron* ht = new HinhTron(73.9);
    cout << hhp->TinhDienTich() << "\t" << hcn->TinhDienTich()
        << "\t" << ht->TinhDienTich();
    cout << endl;
    //vì HinhChuNhat là một loại HinhHocPhang nên có thể gán
    delete hhp;
    hhp = hcn;
    cout << hhp->TinhDienTich() << endl;
    cout << endl << endl;
    delete hcn;
    delete ht;
    return 0;
}