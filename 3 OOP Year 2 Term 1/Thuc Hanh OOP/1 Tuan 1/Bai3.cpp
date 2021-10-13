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

class NgayThang {
private:
    int ngay, thang, nam;

public:
    NgayThang()
    {
        ngay = 1;
        thang = 1;
        nam = 1;
    }
    int getDay() { return this->ngay; }
    int getMonth() { return this->thang; }
    int getYear() { return this->nam; };
    NgayThang(int day, int month, int year)
    {
        if (day > 0 && day < 32)
            ngay = day;
        else
            ngay = 1;
        if (month > 0 && month <= 12)
            thang = month;
        else
            thang = 12;
        if (year > 0)
            nam = year;
        else
            nam = 2000;
    }
};

class SinhVien {
private:
    string mssv;
    string name = "No Name";
    int ngaySinh = 0, thangSinh = 0, namSinh = 0;
    double DLT = 10, DTH = 10;

public:
    void xuat();
    SinhVien()
    {
    }
    SinhVien(string id)
    {
        mssv = id;
    }
    SinhVien(string id, string name, int lt, int th, int day, int month, int year)
    {
        mssv = id;
        this->name = name;
        DLT = lt;
        DTH = th;
        ngaySinh = day;
        thangSinh = month;
        namSinh = year;
    }
    SinhVien(string id, string name, int lt, int th)
    {
        mssv = id;
        this->name = name;
        DLT = lt;
        DTH = th;
    }
    SinhVien(string id, string name, int lt, int th, NgayThang ngay_thang)
    {
        mssv = id;
        this->name = name;
        DLT = lt;
        DTH = th;
        ngaySinh = ngay_thang.getDay();
        thangSinh = ngay_thang.getMonth();
        namSinh = ngay_thang.getYear();
    }
    SinhVien(const SinhVien& other)
    {
        mssv = other.mssv;
        this->name = other.name;
        DLT = other.DLT;
        DTH = other.DTH;
        ngaySinh = other.ngaySinh;
        thangSinh = other.thangSinh;
        namSinh = other.namSinh;
    }
};

void SinhVien::xuat()
{
    cout << "MSSV: " << mssv << ", "
         << "Ho Ten: " << name << ", " << ngaySinh << "/" << thangSinh << "/" << namSinh << ", "
         << "DLT: " << DLT << " DTH: " << DTH << endl;
}
int main()
{
    SinhVien sv1;
    sv1.xuat();
    SinhVien sv2("135233");
    sv2.xuat();
    SinhVien sv3("2", "Minh Nhat", 7, 9.5);
    sv3.xuat();
    SinhVien sv4("123456", "Hoang Nhat Minh", 8, 9.5, 12, 3, 1996);
    sv4.xuat();

    NgayThang n(30, 2, 1996);
    SinhVien sv5("1234", "Ngo Van C ", 5, 6, n);
    sv5.xuat();

    SinhVien sv6(sv5);
    sv6.xuat();
    return 0;
}