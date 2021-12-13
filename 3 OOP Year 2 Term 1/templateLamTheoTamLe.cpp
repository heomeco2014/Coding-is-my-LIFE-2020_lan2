#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

template<typename T>

class Mang
{
private:
    T* data;
    int n;
public:
    Mang();
    Mang(T* data, int n);
    ~Mang();
    void sort();
    int timkiem(const T& key) const;
    void ghifile(char* tenfile);
    void docfile(char* tenfile);
    int timmax()const;
    int timmin()const;
    void xuat()const;
    void nhap();
    bool ktRong()const;
};

template<typename T>
Mang<T>::Mang() :data(NULL), n(0) {}

template<typename T>
Mang<T>::Mang(T* data, int n) {
    this->data = new T[n];
    this->n = n;
    for (int i = 0; i < n; i++)
    {
        this->data[i] = data[i];
    }
}
template<typename T>
Mang<T>::~Mang() {
    delete[] data;
}

template<typename T>
void Mang<T>::sort() {
    std::sort(data, data + n);
}

template<typename T>
int Mang<T>::timkiem(const T& key) const {
    for (int i = 0; i < n; i++)
    {
        if (data[i] == key) return i;
    }
    return -1;
}
template<typename T>
void Mang<T>::ghifile(char* tenfile) {
    ofstream f(tenfile);
    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << data[i] << endl;
    }
    f.close();
}
template<typename T>
void Mang<T>::docfile(char* tenfile) {
    ifstream f(tenfile);
    f >> n;
    data = new int[n];
    for (int i = 0; i < n; i++)
    {
        f >> data[i];
    }
    f.close();
}
template<typename T>
int Mang<T>::timmax()const {
    if (n == 0)return -1;
    int index = -1;
    T max = data[0];
    for (int i = 0; i < n; i++)
    {
        if (data[i] > max) {
            index = i;
            max = data[i];
        }
    }
    return index;
}
template<typename T>
int Mang<T>::timmin()const {
    if (n == 0)return -1;
    int index = -1;
    T min = data[0];
    for (int i = 0; i < n; i++)
    {
        if (data[i] < min) {
            min = data[i];
            index = i;
        }
    }
    return index;
}
template<typename T>
void Mang<T>::xuat()const {
    if (n == 0) return;
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << endl;
    }
}
template<typename T>
void Mang<T>::nhap() {
    cout << "Nhap so luong phan tu " << endl;
    cin >> n;
    data = new T[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> data[i];
    }
}
template<typename T>

bool Mang<T>::ktRong()const {
    return n == 0;
}


class Hocsinh
{
private:
    char hoten[55];
    int tuoi;
    float dtb;
public:
    Hocsinh() :tuoi(0), dtb(0.0) {
        strcpy(hoten, "");
    }
    Hocsinh(char hoten1[], int tuoi, float dtb)
    {
        strcpy(this->hoten, hoten1);
        this->tuoi = tuoi;
        this->dtb = dtb;
    }
    friend ostream& operator << (ostream& os, Hocsinh& r) {
        os << "Ho ten hoc sinh: " << r.hoten << endl;
        os << "Tuoi:" << r.tuoi << endl;
        os << "DTB: " << r.dtb << endl;
        return os;
    }
    friend istream& operator >> (istream& is, Hocsinh& r) {
        is.getline(r.hoten, 55); // clear buffer
        is.getline(r.hoten, 55);
        is >> r.tuoi >> r.dtb;
        char tmp[1];
        return is;
    }
    bool operator > (Hocsinh& r)
    {
        return this->tuoi > r.tuoi;
    }
    bool operator < (const Hocsinh& r) {
        return this->tuoi < r.tuoi;
    }
    friend void sapxep(Hocsinh a[], int n) {
        sort(a, a + n);
    }
};
int main() {
    int a1[] = { 10, 2, 13, 24 };
    string s1[] = { "Kim Tan", "Bi Rain", "Le Roi", "Tran Trang" };
    int n1 = 4;
    Mang<int> mi;
    Mang<string> ms;
    Mang<Hocsinh> mhs;
    mhs.nhap();
    cout << "xong mhs";
    mi.nhap();
    ms.nhap();
    mhs.ghifile("hocsinh.txt");
    mhs.sort();
    ms.sort();
    mi.sort();
    ms.xuat();
    mi.xuat();
    mhs.xuat();
    int kq = ms.timkiem(string("Teo"));
    if (kq >= 0)
        cout << "Tim thay Teo o vi tri " << kq << endl;
    else
        cout << "Khong tim thay Teo" << endl;
    return 0;
}