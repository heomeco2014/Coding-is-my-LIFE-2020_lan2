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

class SinhVien {
private:
    int id;
    string name;
    string ngaySinh;
    double theoryScore, practiceScore;
public:
    SinhVien();
    SinhVien(string ngaySinh);
    SinhVien(string ngaySinh, string name);
    SinhVien(string ngaySinh, string name, double, double);
    SinhVien(string ngaySinh, string name, double, double);
    void Xuat();
};

SinhVien::SinhVien() {
    id = 0;
    name = "NO_NAME";
    ngaySinh = "000000";
    theoryScore = 0;
    practiceScore = 0;
}
void SinhVien::Xuat() {
    cout << "MSSV: " << id << ", HoTen: " << name << ", NgaySinh: " << ngaySinh.substr(0,2) << "/" << ngaySinh.substr(2,2) << "/" << ngaySinh.substr(4,2) << endl;
}
int main() {
    SinhVien sv1;
    sv1.Xuat();
    return 0;
}