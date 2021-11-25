#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <cstring>
using namespace std;

class SinhVien
{
private:
    char* mssv;
    char* hoten;
    static int sl;
public:
    SinhVien();
    SinhVien(const char* mssv, const char* hoten);
    SinhVien(const SinhVien& sv);
    ~SinhVien() {
        --sl;
        delete[] mssv;
        delete[] hoten;
    };
    static int SoLuongSV();
    const SinhVien& operator = (const SinhVien& sv);
    friend ostream& operator << (ostream& os, const SinhVien& sv) {
        os << "MSSV: " << sv.mssv << ", Ten: " << sv.hoten;
        return os;
    }
};
const SinhVien& SinhVien::operator=(const SinhVien& sv) {
    if (this == &sv) return *this;
    delete [] mssv;
    mssv = new char[sizeof(sv.hoten) / sizeof(*sv.hoten)];
    hoten = new char[sizeof(sv.mssv) / sizeof(*sv.mssv)];
    strcpy(mssv, sv.mssv);
    strcpy(hoten, sv.hoten);
    return *this;
}
int SinhVien::sl = 0;
SinhVien::SinhVien() :mssv{ nullptr }, hoten{ nullptr } {
    mssv = new char[1];
    hoten = new char[1];
    mssv[0] = '\0';
    hoten[0] = '\0';
}
SinhVien::SinhVien(const char* id, const char* name) {
    mssv = new char[sizeof(id) / sizeof(*id)];
    hoten = new char[sizeof(name) / sizeof(*name)];
    strcpy(mssv, id);
    strcpy(hoten, name);
    ++sl;
}
SinhVien::SinhVien(const SinhVien& sv) {
    mssv = new char[sizeof(sv.hoten) / sizeof(*sv.hoten)];
    hoten = new char[sizeof(sv.mssv) / sizeof(*sv.mssv)];
    strcpy(mssv, sv.mssv);
    strcpy(hoten, sv.hoten);
    ++sl;
}

int SinhVien::SoLuongSV() {
    return sl;
}
int main() {
   
    return 0;
}