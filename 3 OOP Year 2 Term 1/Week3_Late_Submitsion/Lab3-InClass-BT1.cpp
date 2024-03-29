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

class HocSinh {
private:
    string name;
    double diemA, diemB, diemC, diemAvg;
    int ID;
    static int minimumId;
    static HocSinh sHSDiemTBCaoNhat;
public:
    HocSinh() {
        name = "";
        diemA = diemB = diemC = 0;
        diemAvg = (diemA + diemB + diemC) / 3.0;
        minimumId++;
        ID = minimumId;
    }
    HocSinh(string tenHs, double a, double b, double c) {
        name = tenHs;
        diemA = a;
        diemB = b;
        diemC = c;
        diemAvg = (diemA + diemB + diemC) / 3.0;
        minimumId++;
        ID = minimumId;
        if (sHSDiemTBCaoNhat.diemAvg < diemAvg) {
            sHSDiemTBCaoNhat = *this;
        }
    }
    void DatHoTen(string tenHs) {
        name = tenHs;
    }
    void GanDiem(const double& a, const  double& b, const  double& c) {
        diemA = a;
        diemB = b;
        diemC = c;
        diemAvg = (diemA + diemB + diemC) / 3.0;
        if (sHSDiemTBCaoNhat.diemAvg < diemAvg) {
            sHSDiemTBCaoNhat = *this;
        }
    }
    friend ostream& operator<<(ostream& output, const HocSinh& stu) {
        cout << "HS: " << stu.name << ", MS: " << stu.ID << ", DTB: " << stu.diemAvg;
        return output;
    }
    static HocSinh HSDiemTBCaoNhat() {
        return sHSDiemTBCaoNhat;
    }

};
int HocSinh::minimumId = 1363000;
HocSinh HocSinh::sHSDiemTBCaoNhat = HocSinh();
int main() {
    HocSinh hs1;
    hs1.DatHoTen("Nguyen Van A");
    hs1.GanDiem(7, 8, 10);

    HocSinh hs2("Tran Thi B", 5, 8, 4.5);
    HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
    HocSinh hs4("Le Van D", 7.5, 9, -10);
    cout << hs1 << endl
        << hs2 << endl
        << hs3 << endl
        << hs4 << endl;

    cout << "Hoc sinh co diem TB cao nhat: " << endl;
    cout << HocSinh::HSDiemTBCaoNhat() << endl;
    return 0;
}