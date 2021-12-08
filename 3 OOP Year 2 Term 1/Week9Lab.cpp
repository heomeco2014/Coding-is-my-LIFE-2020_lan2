#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

class HinhHoc
{
public:
    HinhHoc() {}
    virtual double TinhDienTich() {
        return 0;
    }
    virtual double TongChuVi() {
        return 0;
    }
    virtual double DienTichXungQuanh() {
        return 0;
    }
   
};
class HinhTamGiacDeu
    :public HinhHoc
{
private:
    double a;
public:
    HinhTamGiacDeu() :HinhHoc(), a(0) {};
    HinhTamGiacDeu(double canh1) :HinhHoc(), a(abs(canh1)) {}
    double TongChuVi() {
        return a * (3);
    }
    double TinhDienTich() {
        return sqrt(3) / 4 * 1.0 * a * a;
    }
    friend ostream& operator >> (ostream& os, const HinhHoc h) {
        cout << "Nhap canh cua tam giac vuong: " << endl;
    }
};

class HinhChuNhat
    :public HinhHoc
{
private:
    double chieuDai, chieuRong;
public:
    HinhChuNhat() {
        chieuRong = 0;
        chieuDai = 0;
    };
    HinhChuNhat(const double& cd, const double& cr) {
        chieuDai = (cd == 0) ? 1 : abs(cd);
        chieuRong = (cr == 0) ? 1 : abs(cr);
    }
    double TinhDienTich() {
        return chieuRong * chieuDai;
    }
    double TongChuVi() {
        return 2 * (chieuDai + chieuRong);
    }
};
#define PI 3.14159
class HinhTron :public HinhHoc
{
public:
    HinhTron() {
        banKinh = 0;
    }
    HinhTron(const double& bk);
    double TinhDienTich() {
        return PI * banKinh * banKinh;
    }
    double TongChuVi() {
        return 2 * banKinh * PI;
    }
private:
    double banKinh;
};
HinhTron::HinhTron(const double& bk)
{
    banKinh = (bk == 0) ? 1 : abs(bk);
}


class QuanLyHinhHocPhang
{
private:
    vector<HinhHoc*> hhp;
public:
    QuanLyHinhHocPhang() {
        hhp.resize(0);
    };
    ~QuanLyHinhHocPhang() {
        if (hhp.empty() == false) {
            for (int i = 0; i < hhp.size(); i++)
            {
                delete hhp[i];
            }
        }
    }
    void AddHinh(HinhHoc* hp) {
        hhp.push_back(hp);
    }
    double TongDienTich() {
        double res = 0;
        if (hhp.empty() == false) {
            for (vector<HinhHoc*>::iterator it = hhp.begin();it != hhp.end();it++) {
                if (*it) {
                    res += (*it)->TinhDienTich();
                }
            }
        }
        return res;
    }
    double TongChuVi() {
        double res = 0;
        if (!hhp.empty()) {
            for (vector<HinhHoc*>::iterator it = hhp.begin(); it != hhp.end(); it++) {
                if (*it)
                    res += (*it)->TongChuVi();
            }
        }
        return res;
    }
};
int main() {
    QuanLyHinhHocPhang ql;
    ql.AddHinh(new HinhChuNhat(5.6, 2.3));
    ql.AddHinh(new HinhTamGiacDeu(-1.5));
    ql.AddHinh(new HinhTron(12.7));

    cout << "Tong Dien tich: " << ql.TongDienTich() << endl;
    cout << "Tong Chu vi: " << ql.TongChuVi() << endl;
    cout << endl << endl;
    return 0;
}