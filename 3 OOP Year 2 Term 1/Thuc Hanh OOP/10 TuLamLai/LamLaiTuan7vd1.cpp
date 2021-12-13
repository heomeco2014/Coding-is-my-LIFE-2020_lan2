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

class NhanVien
{
private:
    string hoTen, diaChi;
public:
    NhanVien() :hoTen(""), diaChi("") {}

    friend ostream& operator <<(ostream& os, const NhanVien& nv) {
        os << nv.hoTen << " (" << nv.diaChi << ")";
        return os;
    }
    NhanVien(const string& hoten, const string& diachi) {
        hoTen = hoten;
        diaChi = diachi;
    }
};

class NhanVienKiThuat :public NhanVien {
private:
    string chungChiNganh;
public:
    NhanVienKiThuat() :NhanVien(), chungChiNganh("") {}
    NhanVienKiThuat(const string& hoten, const string& diachi, const string& chungchi) :NhanVien(hoten, diachi), chungChiNganh(chungchi) {}
    friend ostream& operator <<(ostream& os, const NhanVienKiThuat& nvkt) {
        os << (NhanVien)nvkt;
        os << " (" << nvkt.chungChiNganh << ")";
        return os;
    }
};
int main() {
    NhanVienKiThuat nvkt("Nguyen Van A", "Nguyen Van Cu, Q.5", "CNTT");
    cout << nvkt;
    return 0;
}