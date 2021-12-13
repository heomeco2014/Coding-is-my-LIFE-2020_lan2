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

class HocSinh
{
private:
    string name;
    double A, B, C, dtb;
    static int sid;
    int m_id;
    static HocSinh sHSDiemTBCaoNhat;
public:
    static HocSinh HSDiemTrungBinhCaoNhat() {
        return sHSDiemTBCaoNhat;
    }
    HocSinh(/* args */) {
        name = "";
        A = B = C = dtb = 0.0;
        m_id = ++sid;
    }
    HocSinh(const string& ten, const double& a, const double& b, const double& c) {
        name = ten;
        A = abs(a);
        B = abs(b);
        C = abs(c);
        dtb = (abs(A) + abs(B) + abs(C)) / 3.0;
        m_id = ++sid;
        if (dtb > sHSDiemTBCaoNhat.dtb) {
            sHSDiemTBCaoNhat = *this;
        }
    }
    void DatHoTen(const string& ten) {
        name = ten;
    }
    void GanDiem(const double& a, const double& b, const double& c) {
        A = a;
        B = b;
        C = c;
        dtb = (abs(A) + abs(B) + abs(C)) / 3.0;
        if (dtb > sHSDiemTBCaoNhat.dtb) {
            sHSDiemTBCaoNhat = *this;
        }
    }
    friend ostream& operator <<(ostream& os, const HocSinh& hs) {
        os << fixed << "HS: " << hs.name << ", MS: " << hs.m_id << ", DTB: " << setprecision(2) << hs.dtb;
        return os;
    }
};
HocSinh HocSinh::sHSDiemTBCaoNhat = HocSinh();
int HocSinh::sid = 136300;

int main() {
    HocSinh hs1;
    hs1.DatHoTen("Nguyen Van A");
    hs1.GanDiem(7, 8, 10);
    HocSinh hs2("Tran Thi B", 5, 8, 4.5);
    HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
    HocSinh hs4("Le Van D", 7.5, 9, -10);
    cout << hs1 << endl << hs2 << endl << hs3 << endl << hs4 << endl << endl;
    cout << HocSinh::HSDiemTrungBinhCaoNhat() << endl;
    return 0;
}