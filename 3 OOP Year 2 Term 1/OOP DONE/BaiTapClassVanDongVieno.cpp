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

class VanDongVien {
protected:
    string ho_ten;
    string mon_thi_dau;
    int tuoi;
    double can_nang;
    double chieu_cao;

public:
    VanDongVien() {
        this->ho_ten = this->mon_thi_dau = "";
        this->tuoi = 0;
        this->can_nang = this->chieu_cao = 0;
    };
    VanDongVien(string name, string field, int age, double weigh, double height)
        : ho_ten(name), mon_thi_dau(field), tuoi(age), can_nang(weigh), chieu_cao(height) {}
    ~VanDongVien() { cout << "Huy bo van dong vien " << ho_ten << endl; }

    // Nap chong` toan tu ">"
    bool operator>(const VanDongVien &obj) {
        if (this->chieu_cao > obj.chieu_cao)
            return true;
        else if (this->chieu_cao < obj.chieu_cao)
            return false;
        else if (this->can_nang > obj.can_nang)
            return true;
        return false;
    }

    friend istream &operator>>(istream &is, VanDongVien &obj) {
        cin.ignore();
        cout << "Nhap Ho Ten: ";
        // fflush(stdin);
        getline(is, obj.ho_ten);
        cout << "Nhap Mon Thi Dau: ";
        // fflush(stdin);
        getline(is, obj.mon_thi_dau);
        cout << "Nhap Tuoi: ";
        is >> obj.tuoi;
        cout << "Nhap Can Nang: ";
        is >> obj.can_nang;
        cout << "Nhap Chieu Cao: ";
        is >> obj.chieu_cao;
        return is;
    }

    friend ostream &operator<<(ostream &os, VanDongVien obj) {
        cout << "Ho Ten: " << obj.ho_ten << endl;
        cout << "Mon Thi Dau: " << obj.mon_thi_dau << endl;
        cout << "Tuoi: " << obj.tuoi << endl;
        cout << "Can Nang: " << obj.can_nang << endl;
        cout << "Chieu cao: " << obj.chieu_cao << endl;
        return os;
    }
};

 
void swap(VanDongVien &a, VanDongVien &b)
{
    VanDongVien temp = a;
    a = b;
    b = temp;
}
 
void Bubblesort(VanDongVien arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int main() {
    VanDongVien p("Nguyen Van A", "Bong Da", 20, 178, 70.5);
    cout << p;

     cout << "Nhap So Luong: "; int n; cin >> n;
    VanDongVien *arr = new VanDongVien[n];
 
    for (int i = 0; i < n; ++i) cin >> arr[i];
 
    cout << endl << endl;
    for (int i = 0; i < n; ++i) cout << arr[i] << endl;
    
    cout << "Sort" << endl;
    Bubblesort(arr,n);
    for (int i = 0; i < n; ++i) cout << arr[i] << endl;
 
    return 0;
}