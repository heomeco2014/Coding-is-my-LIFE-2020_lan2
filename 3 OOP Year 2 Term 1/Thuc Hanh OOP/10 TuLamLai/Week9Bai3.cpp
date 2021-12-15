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

class ChiTietMay {
protected:
    int maSo;
public:
    ChiTietMay() :maSo(0) {};
    ChiTietMay(const int& ms) {
        maSo = ms;
    }
    int getMaSo() { return maSo; }
    virtual double tongTrongLuong() { return 0; }
    virtual double tongGiaThanh() { return 0; }
    virtual void nhap() {
        cout << "Nhap ma so cua chi tiet may: ";
        cin >> maSo;
    }
    virtual bool searchChiTiet(const int& key) {
        return key == maSo;
    }
};

class ChiTietDon :public ChiTietMay {
protected:
    double giaThanh, trongLuong;
public:
    ChiTietDon() :giaThanh(0), trongLuong(0) {}
    ChiTietDon(const int& ms, const double& gt, const double& tl) :ChiTietMay(ms), giaThanh(gt), trongLuong(tl) {}
    void nhap() {
        ChiTietMay::nhap();
        cout << "Nhap gia thanh cua chi tiet don: ";
        cin >> giaThanh;
        cout << "Nhap trong luong cua chi tiet don: ";
        cin >> trongLuong;
    }
    double tongTrongLuong() {
        return trongLuong;
    }
    double tongGiaThanh() {
        return giaThanh;
    }
    bool searchChiTiet(const int& id) {
        return id == maSo;
    }
};
class ChiTietPhuc :public ChiTietMay {
protected:
    vector<ChiTietDon> ds;
public:
    double tongTrongLuong() {
        int sumTrongLuong = 0;
        for (int i = 0; i < ds.size(); i++)
        {
            sumTrongLuong += ds[i].tongTrongLuong();
        }
        return sumTrongLuong;
    }
    double tongGiaThanh() {
        int sumGiaThanh = 0;
        for (int i = 0; i < ds.size(); i++)
        {
            sumGiaThanh += ds[i].tongGiaThanh();
        }
        return sumGiaThanh;
    }
    void nhap() {
        ChiTietMay::nhap();
        int soLuong;
        cout << "Chon so luong chi tiet don ban muon nhap: ";
        cin >> soLuong;
        ChiTietDon a;
        for (int i = 0; i < soLuong; i++)
        {
            a.nhap();
            ds.push_back(a);
        }
    }
    bool searchChiTiet(const int& id) {
        for (int i = 0; i < ds.size(); i++)
        {
            if (ds[i].searchChiTiet(id)) {
                return true;
            }
        }
        return 0;
    }
};

class May {
private:
    vector<ChiTietMay*> dsChiTietMay;
    double phuKienKetNoi;
    double congLapRap;
public:
    void nhapChiTietMay() {
        cout << "Nhap vao chi tiet may cau tao thanh co may";
        cout << "\nChi tiet don: 1 " << endl;
        cout << "Chi tiet phuc: 2 " << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            ChiTietDon* ctd = new ChiTietDon;
            ctd->nhap();
            dsChiTietMay.push_back(ctd);
        }
        else if (choice == 2) {
            ChiTietPhuc* ctphuc = new ChiTietPhuc;
            ctphuc->nhap();
            dsChiTietMay.push_back(ctphuc);
        }
        else {
            cout << "Thay nhap sai roi! Chay lai chuong trinh thay oi!" << endl;
        }
    }
    double tinhTrongLuongFullmay() {
        double sum = 0;
        cout << "Nhap gia phu kien ket noi: ";
        cin >> phuKienKetNoi;
        for (int i = 0; i < dsChiTietMay.size(); i++)
        {
            sum += dsChiTietMay[i]->tongTrongLuong();
        }
        cout << "Trong luong: " << sum + 0.1 * phuKienKetNoi;
        return sum + 0.1 * phuKienKetNoi;
    }
    double tinhGiaThanhFullMay() {
        double sum = 0;
        cout << "Nhap gia cong lap rap: ";
        cin >> congLapRap;
        for (int i = 0; i < dsChiTietMay.size(); i++)
        {
            sum += dsChiTietMay[i]->tongGiaThanh();
        }
        cout << "Gia thanh " << sum + 0.2 * congLapRap;
        return sum + 0.2 * congLapRap;
    }
    bool searchChiTiet(const int& id) {
        for (int i = 0; i < dsChiTietMay.size(); i++)
        {
            if (dsChiTietMay[i]->searchChiTiet(id)) {
                return true;
            }
        }
        return 0;
    }
};

int main() {
    May a;
    a.nhapChiTietMay();
    a.tinhGiaThanhFullMay();
    cout << endl;
    a.tinhTrongLuongFullmay();
    cout << endl;
    if (a.searchChiTiet(111)) cout << "Tim thay chi tiet";
    else cout << "Khong tim thay chi tiet" << endl;
    return 0;
}