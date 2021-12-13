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
class SinhVien
{
private:
    char* mssv;
    char* hoten;
    static int sl;
public:
    SinhVien() {
        mssv = new char[1];
        hoten = new char[1];
        mssv = '\0';
        hoten = '\0';
        sl++;
    }
    SinhVien(const char* mssv, const char* hoten) {
        if (mssv == nullptr) {
            this->mssv = new char[1];
            this->mssv[0] = '\0';
        }
        else
        {
            this->mssv = new char[strlen(mssv) + 1];
            strcpy(this->mssv, mssv);
        }

        if (hoten == nullptr) {
            this->hoten = new char[1];
            this->hoten[0] = '\0';
        }
        else
        {
            this->hoten = new char[strlen(hoten) + 1];
            strcpy(this->hoten, hoten);
        }
        sl++;
    }
    SinhVien(const SinhVien& sv) {
        mssv = new char[strlen(sv.mssv) + 1];
        hoten = new char[strlen(sv.hoten) + 1];
        strcpy(this->hoten, sv.hoten);
        strcpy(this->mssv, sv.mssv);
        sl++;
    }
    const SinhVien& operator = (const SinhVien& sv) {
        if (this != &sv)
        {
            delete[] mssv;
            delete[] hoten;
            mssv = new char[strlen(sv.mssv) + 1];
            hoten = new char[strlen(sv.hoten) + 1];
            strcpy(mssv, sv.mssv);
            strcpy(hoten, sv.hoten);
        }
    }
    ~SinhVien() {
        delete[] mssv;
        delete[] hoten;
        sl--;
    }
    static int SoLuongSV() { return sl; }
};

int main() {
    char* a = new char;
    char* b = new char;
    return 0;
}