#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

class Hocsinh
{
public:
    Hocsinh() :hoten(""), tuoi(0), dtb(0) {}
    Hocsinh(char hoten1[], int tuoi, float dtb)
    {
        strcpy(hoten, hoten1);
        this->tuoi = tuoi;
        this->dtb = dtb;
    }
    friend ostream& operator << (ostream& os, Hocsinh& r) {
        os << "Ten hoc sinh: " << r.hoten << "| Tuoi hoc sinh: " << r.tuoi << "| DTB: " << r.dtb;
        return os;
    }
    friend istream& operator >> (istream& is, Hocsinh& r) {
        cout << "Nhap ten hoc sinh: " << endl;
        is.ignore();
        is.getline(r.hoten, 55);
        cout << "Nhap tuoi hoc sinh:  " << endl;
        is >> r.tuoi;
        cout << "Nhap dtb hoc sinh: " << endl;
        is >> r.dtb;
        return is;
    }
    bool operator > (Hocsinh& r)
    {
        return this->dtb > r.dtb;
    }
    bool operator < (const Hocsinh& r) {
        return this->dtb < r.dtb;
    }
    friend void sapxep(Hocsinh a[], int n) {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
private:
    char hoten[55];
    int tuoi;
    float dtb;
};

template <typename T>

class Mang
{
public:
    Mang() :data(NULL), n(0) {};
    Mang(T* data, int n) {
        this->data = data;
    }
    ~Mang() {
        delete[]data;
    }
    void sort() {

    }
    int timkiem(const T& key) const {
        for (int i = 0; i < n; i++)
        {
            if (data[i] == key) return i;
        }
        return -404;
    }
    void ghifile(char* tenfile) {
        ofstream f(tenfile);
        if (f.is_open()) {
            for (int i = 0; i < n; i++)
            {
                f << data[i];
            }
        }
        else cout << "Error, file cannot be opened" << endl;
        f.close();
    }
    int timmax()const {
        int max = INT_MIN;
        int pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (data[i] > max)
            {
                max = data[i];
                pos = i;
            }
        }
        return pos;
    }
    int timmin()const {
        int min = INT_MAX;
        int pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (data[i] > min)
            {
                min = data[i];
                pos = i;
            }
        }
        return pos;
    }
    void nhap() {
        cout << "Nhap so luong: " << endl;
        cin >> n;
        data = new T[n];
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
    }
    void xuat() {
        for (int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
            cout << endl;
        }

    }
    bool ktRong()const {
        return data == NULL;
    }
private:
    T* data;
    int n;
};


int main()
{
    int a1[] = { 10, 2, 13, 24 };
    string s1[] = { "Kim Tan", "Bi Rain", "Le Roi", "Tran Trang" };
    int n1 = 4;
    Mang<int> mi;
    Mang<string> ms;
    Mang<Hocsinh> mhs;
    mhs.nhap();
    mi.nhap();
    ms.nhap();
    char* tenfile;
    strcpy(tenfile, "hocsinh.txt");
    mhs.ghifile(tenfile);
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
