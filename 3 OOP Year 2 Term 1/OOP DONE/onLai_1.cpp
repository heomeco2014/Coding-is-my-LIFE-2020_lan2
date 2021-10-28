#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class HocSinh {
private:
    string name;
    int id;
    double diemA, diemB, diemC, diemTb;
    static HocSinh sHSDiemTBCaoNhat;
    static int minimumID;

public:
    HocSinh();
    HocSinh(const string&, const double&, const double&, const double&);
    void DatHoTen(const string&);
    void GanDiem(const double&, const double&, const double&);
    static HocSinh HSDiemTBCaoNhat();
    friend ostream& operator<<(ostream&, const HocSinh&);
};

int HocSinh::minimumID = 136300;

HocSinh HocSinh::sHSDiemTBCaoNhat = HocSinh();

HocSinh::HocSinh()
{
    name = "";
    diemA = diemB = diemC = 0;
    diemTb = (diemA + diemB + diemC) / 3.0;
    id = ++minimumID;
}
HocSinh::HocSinh(const string& hoVaTen, const double& d1, const double& d2, const double& d3)
    : name(hoVaTen)
    , diemTb((abs(d1) + abs(d2) + abs(d3)) / 3.0)
    , id(++minimumID)
{
    if (diemTb > sHSDiemTBCaoNhat.diemTb)
        sHSDiemTBCaoNhat = *this;
}

void HocSinh::DatHoTen(const string& hoVaTen) {
    name = hoVaTen;
}

void HocSinh::GanDiem(const double& d1, const double& d2, const double& d3) {
    diemA = d1;
    diemB = d2;
    diemC = d3;
    diemTb = (diemA + diemB + diemC) / 3.0;

    if (sHSDiemTBCaoNhat.diemTb < diemTb)
        sHSDiemTBCaoNhat = *this;
}

HocSinh HocSinh::HSDiemTBCaoNhat() {
    return sHSDiemTBCaoNhat;
}
ostream& operator<<(ostream& os, const HocSinh& hs)
{
    os << fixed << "HS: " << hs.name << ", MS: " << hs.id << ", DTB: " << setprecision(2) << hs.diemTb;
    return os;
}

int main()
{
    HocSinh hs1;
    hs1.DatHoTen("Nguyen Van A");
    hs1.GanDiem(7, 8, 10);
    HocSinh hs2("Tran Thi B", 5, 8, 4.5);
    HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
    HocSinh hs4("Le Van D", 7.5, 9, -10);

    cout << hs1 << endl
        << hs2 << endl
        << hs3 << endl
        << hs4 << endl
        << endl;

    cout << "Hoc sinh co diem TB cao nhat:" << endl;
    cout << HocSinh::HSDiemTBCaoNhat() << endl;
    return 0;
}