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

class Phu_nu {

public:
    Phu_nu() {
    }

    Phu_nu(const string &ho_ten, int tuoi, bool con_zin = true)
        : ho_ten(ho_ten), con_zin(con_zin), tuoi(tuoi) {
    }
    ~Phu_nu() {
        cout << "Chia tay " << ho_ten << endl;
    }

    void trang_diem() {
    }
    virtual string choi_nhac_cu(string nhac_cu) {
        return "Phu nu choi nhac cu ";
    }
    void va_zin() {
        con_zin = (tuoi < 25 ? true : false);
    }
    void show_hang() {
        cout << ho_ten << " " << (con_zin ? "con zin " : "mat zin ") << tuoi << " tuoi " << endl;
    }

protected:
    string ho_ten;
    bool con_zin;
    int tuoi;
};

class Gai_Ngoan : public Phu_nu {
public:
    Gai_Ngoan(const string &ht, int age, bool zin = true) : Phu_nu(ht, age, zin) {}

    void noi_tro() { cout << ho_ten << " dang noi tro" << endl; }
    string choi_nhac_cu() { return "gai Ngoan choi nhac cu "; }
};

class Gai_Hu : public Phu_nu {
public:
    Gai_Hu(const string &ht, int age, bool zin = true) : Phu_nu(ht, age, zin) {}
    void di_bar() {
        cout << ho_ten << " di bar" << endl;
    }
    string choi_nhac_cu() { return "gai Hu choi nhac cu "; }
};

int main() {
    Phu_nu *maria = new Gai_Hu("Maria Ozawa", 22, false);
    maria->show_hang();
    maria->va_zin();
    maria->show_hang();
    // maria->di_bar();
    cout << maria->choi_nhac_cu("ken") << endl;

    delete maria;

    return 0;
}