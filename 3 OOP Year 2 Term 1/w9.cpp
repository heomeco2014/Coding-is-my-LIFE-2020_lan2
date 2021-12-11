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
class HinhHocPhang
{
public:
    HinhHocPhang() {}
    virtual double TinhDienTich() {
        return 0;
    }
    virtual double TongChuVi() {
        return 0;
    }
    virtual double TinhTheTich() { return 0; }
    virtual double TinhDienTichXungQuanh() { return 0; }
    virtual void DisplayDetail() = 0;
};
class HinhTamGiacDeu
    :public HinhHocPhang
{
private:
    double a;
public:
    HinhTamGiacDeu() :HinhHocPhang(), a(0) {};
    HinhTamGiacDeu(double canh1) :HinhHocPhang(), a(abs(canh1)) {}
    double TongChuVi() {
        return a * 3;
    }
    double TinhDienTich() {
        return sqrt(3) / 4 * 1.0 * (a * a);
    }

    void DisplayDetail() {
        cout << "Hinh tam giac deu (a = " << a << " ), co P = " << TongChuVi() << " va S = " << TinhDienTich() << endl;
    }

};

class HinhChuNhat
    :public HinhHocPhang
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

    void DisplayDetail() {
        cout << "Hinh chu nhat (chieu dai = " << chieuDai << ", chieu rong  = " << chieuRong << "), co P = " << TongChuVi() << " va S = " << TinhDienTich() << endl;
    }

};
class HinhVuong
    :public HinhHocPhang
{
private:
    double canh;
public:
    HinhVuong() {
        canh = 0;
    };
    HinhVuong(const double& cd) {
        canh = (cd == 0) ? 1 : abs(cd);
    }
    double TinhDienTich() {
        return canh * canh;
    }
    double TongChuVi() {
        return canh * 4;
    }

    void DisplayDetail() {
        cout << "Hinh vuong (canh = " << canh << "), co P = " << TongChuVi() << " va S = " << TinhDienTich() << endl;
    }

};
#define PI 3.14159
class HinhTron :public HinhHocPhang
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
    void DisplayDetail() {
        cout << "Hinh tron co ban kinh = " << banKinh << " co P = " << TongChuVi() << " va S = " << TinhDienTich() << endl;
    }
private:
    double banKinh;
};
HinhTron::HinhTron(const double& bk)
{
    banKinh = (bk == 0) ? 1 : abs(bk);
}

class HinhCau :public HinhTron {
public:
    HinhCau() { banKinh = 0; }
    HinhCau(const double& bk) :banKinh(bk) {};
    double TinhTheTich() {
        return 1 / 3 * 1.0 * PI * banKinh;
    }
    void DisplayDetail() {
        cout << "Hinh cau (ban kinh = " << banKinh << "), co V = " << TinhTheTich() << endl;
    }

private:
    double banKinh;
};

class HinhLapPhuong :public HinhHocPhang
{
private:
    double canh;
public:
    HinhLapPhuong() :canh(0) {};
    HinhLapPhuong(double canh1) :canh(canh1) {};
    double TinhDienTichXungQuanh() {
        return canh * canh * 4;
    }
    double TinhTheTich() {
        return canh * canh * 6;
    }
    void DisplayDetail() {
        cout << "Hinh lap phuong (canh = " << canh << "), co S xung quanh = " << TinhDienTichXungQuanh() << " va V = " << TinhTheTich() << endl;
    }
};
int main() {
    // QuanLyHinhHoc ql;
    // // ql.AddHinh(new HinhVuong(5.6, 2.3));
    // ql.AddHinh(new HinhTamGiacDeu(-1.5));
    // // ql.AddHinh(new HinhTron(12.7));
    // cout << "Tong Dien tich: " << ql.TongDienTich() << endl;
    // cout << "Tong Chu vi: " << ql.TongChuVi() << endl;
    // cout << endl << endl;
    HinhChuNhat hcn(6.2, 5.2);
    hcn.DisplayDetail();
    HinhTron ht(2);
    ht.DisplayDetail();
    HinhVuong hv(5);
    hv.DisplayDetail();
    HinhTamGiacDeu tgd(2);
    tgd.DisplayDetail();

    HinhCau hc1(10);
    hc1.DisplayDetail();

    HinhLapPhuong hlp1(5);
    hlp1.DisplayDetail();
    return 0;
}