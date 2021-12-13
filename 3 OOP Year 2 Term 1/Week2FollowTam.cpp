#include <iostream>  
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <ostream>
using namespace std;

class HocSinh {
private:
    string m_hoVaten;
    double diemA, diemB, diemC, diemTb;
    int m_id;
    static HocSinh sHSDiemTBCaoNhat;
public:
    static int sid;
    HocSinh();
    HocSinh(const string&, const double, const double, const double);
    void GanDiem(const double&, const double&, const double&);
    void DatHoTen(const string&);
    static HocSinh HSDiemTBCaoNhat();
    friend ostream& operator<<(ostream&, const HocSinh&);
};
int HocSinh::sid = 1363000;
HocSinh HocSinh::sHSDiemTBCaoNhat = HocSinh();
ostream& operator << (ostream& os, const HocSinh& hs) {
    os << fixed << "HS: " << hs.m_hoVaten << ", MS: " << hs.m_id << ", DTB: " << setprecision(2) << hs.diemTb;
    return os;
}
HocSinh::HocSinh() :m_hoVaten(" "), diemA(0), diemB(0), diemC(0), diemTb(0), m_id(++sid) {}
HocSinh::HocSinh(const string& hoTen, const double diemA, const double diemB, const double diemC) {
    m_hoVaten = hoTen;
    this->diemA = abs(diemA);
    this->diemB = abs(diemB);
    this->diemC = abs(diemC);
    this->diemTb = (abs(diemA) + abs(diemB) + abs(diemC)) / 3.0;
    if (sHSDiemTBCaoNhat.diemTb < diemTb) {
        sHSDiemTBCaoNhat = *this;
    }
}
void HocSinh::DatHoTen(const string& name) {
    m_hoVaten = name;
}

void HocSinh::GanDiem(const double& A, const double& B, const double& C) {
    this->diemA = A;
    this->diemB = B;
    this->diemC = C;
    diemTb = (abs(this->diemA) + abs(this->diemB) + abs(this->diemC)) / 3.0;
    if (sHSDiemTBCaoNhat.diemTb < diemTb) {
        sHSDiemTBCaoNhat = *this;
    }
}

HocSinh HocSinh::HSDiemTBCaoNhat() {
    return sHSDiemTBCaoNhat;
}
int main() {
    HocSinh hs1;
    hs1.DatHoTen("Nguyen Van A");
    hs1.GanDiem(7, 8, 10);
    HocSinh hs2("Tran Thi B", 5, 8, 4.5);
    HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
    HocSinh hs4("Le Van D", 7.5, 9, -10);
    cout << hs1 << endl << hs2 << endl << hs3 << endl << hs4 << endl << endl;
    cout << HocSinh::HSDiemTBCaoNhat() << endl;
    return 0;
}