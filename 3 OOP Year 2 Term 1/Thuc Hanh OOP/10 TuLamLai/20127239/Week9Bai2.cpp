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


class NhanVien {
protected:
    string maSo, hoTen;
    static int sl;
public:
    NhanVien() :maSo(""), hoTen("") {
        sl++;
    }
    NhanVien(const string& ms, const string& ht) {
        maSo = ms;
        hoTen = ht;
        sl++;
    }
    virtual double TinhLuong() { return 0; }
    virtual NhanVien* Nhap(NhanVien* p) {

        cout << "Nhap ma so: "; cin >> p->maSo;
        cout << "Nhap ho ten: "; cin >> p->hoTen;
        return p;
    }
    virtual void Xuat() {
        return;
    }
    virtual vector<NhanVien*> NhapDsNhanVien() {
        int soLuong;
        cout << "Nhap so luong nhan vien: ";
        cin >> soLuong;
        vector<NhanVien*> res;
        for (int i = 0; i < soLuong; i++)
        {
            NhanVien* tmp = new NhanVien;
            tmp = Nhap(tmp);
            res.push_back(tmp);
            sl++;
        }
        return res;
    }
    // friend istream& operator >> (istream& is, NhanVien& nv) {
    //     cout << "Nhap ma so: "; is >> nv.maSo;
    //     cout << "Nhap ho ten: "; is >> nv.hoTen;
    // }
    friend ostream& operator <<(ostream& os, NhanVien& nv) {
        os << nv.hoTen << " " << nv.maSo << endl;
        return os;
    }
};
int NhanVien::sl = 0;
class NhanVienSanXuat :public NhanVien {
protected:
    int soSanPham;

public:
    double TinhLuong() {
        return soSanPham * 20;
    }
    NhanVienSanXuat* Nhap() {
        NhanVien::Nhap(this);
        cout << "Nhap so san pham: "; cin >> soSanPham;
        return this;
    }
    void Xuat() {
        cout << maSo << " " << hoTen << " " << soSanPham << "Luong: " << TinhLuong() << endl;
    }
};
class NhanVienCongNhat :public NhanVien {
private:
    int soNgayCong;
public:
    double TinhLuong() {
        return soNgayCong * 50;
    }
    NhanVienCongNhat* Nhap() {
        NhanVien::Nhap(this);
        cout << "Nhap so ngay cong: "; cin >> soNgayCong;
        return this;
    }
    void Xuat() {
        cout << maSo << " " << hoTen << " " << soNgayCong << "Luong: " << TinhLuong() << endl;
    }
};
class NhanVienQuanLi :public NhanVien {
private:
    int luongCoBan;
    double heSoLuong;
    static int slql;

public:
    NhanVienQuanLi() :NhanVien() {
        slql++;
    }
    NhanVienQuanLi(const string& ms, const string& ht, const int& lcb, const double& heSoLuong) :NhanVien(ms, ht) {
        slql++;
    }
    double TinhLuong() {
        return luongCoBan * heSoLuong;
    }
    NhanVienQuanLi* Nhap() {
        NhanVien::Nhap(this);
        cout << "Nhap luong co ban: "; cin >> luongCoBan;
        cout << "Nhap he so luong: "; cin >> heSoLuong;
        return this;
    }
    int getNhanVienQuanli() { return slql; }
    void Xuat() {
        cout << maSo << " " << hoTen << "LCB: " << luongCoBan << "HSL:" << heSoLuong << "Luong: " << TinhLuong() << endl;
    }
};

class CongTy
{
private:
    vector<NhanVien*> ds;
public:
    void themNhanVien(NhanVien* nv) {
        ds.push_back(nv);
    }
    void XuatDanhSach() {
        for (int i = 0; i < ds.size(); i++)
        {
            ds[i]->Xuat();
        }
    }
    void XuatDanhSachTheoCapBac() {
        for (int i = 0; i < ds.size(); i++)
        {
            for (int j = i + 1; j < ds.size(); j++)
            {
                if (ds[i]->TinhLuong() < ds[i]->TinhLuong()) {
                    swap(ds[i], ds[j]);
                }
            }
        }
        for (int i = 0; i < ds.size(); i++)
        {
            ds[i]->Xuat();
        }

    }
    void taoDanhSach() {
        int n;
        cout << "Nhap So Luong Nhan Vien:";
        cin >> n;
        cout << "Chon 1 de tao Nhan Vien San Xuat " << endl;
        cout << "Chon 2 de tao Nhan Vien Cong Nhat " << endl;
        cout << "Chon 3 de tao Nhan Vien Quan Ly " << endl;
        int choose;
        for (int i = 0; i < n; i++) {
            cout << "Nhap lua chon: ";
            cin >> choose;
            if (choose -= 1) {
                NhanVienSanXuat* a = new NhanVienSanXuat();
                a->Nhap();
                themNhanVien(a);
            }
            else if (choose -= 2) {
                NhanVienCongNhat* a = new NhanVienCongNhat();
                a->Nhap();
                themNhanVien(a);
            }
            else if (choose = -3) {
                NhanVienQuanLi* a = new NhanVienQuanLi();
                a->Nhap();
                themNhanVien(a);
            }
        }
    }
    int getSoLuong() {
        return ds.size();
    }
    void TongNhanVienQuanLi() {
        int count = 0;
        for (int i = 0; i < ds.size(); i++)
        {
            if (dynamic_cast<NhanVienQuanLi*>(ds[i])) {
                count++;
            }
        }
        cout << "Tong so nhan vien quan li: " << count;
    }

};

int main() {
    CongTy a;
    a.taoDanhSach();
    a.XuatDanhSach();
    a.TongNhanVienQuanLi();
    a.XuatDanhSachTheoCapBac();

    // NhanVien* nv1 = new NhanVien;
    // vector<NhanVien*> ds = nv1->NhapDsNhanVien();
    // for (int i = 0; i < ds.size(); i++)
    // {
    //     cout << *ds[i] << endl;
    // }

    // NhanVienSanXuat* nvsx1 = new NhanVienSanXuat;
    // nvsx1->Nhap();
    // cout << nvsx1->TinhLuong();
    // cout << nvsx1->hoTen;
    // cout << endl;
    // NhanVienCongNhat* nvcn1 = new NhanVienCongNhat;
    // nvcn1->Nhap();
    // cout << nvcn1->TinhLuong();
    // cout << nvcn1->hoTen;
    // cout << endl;
    // NhanVienQuanLi* nvql1 = new NhanVienQuanLi;
    // nvql1->Nhap();
    // cout << nvql1->TinhLuong();
    // cout << nvql1->hoTen;
    return 0;
}