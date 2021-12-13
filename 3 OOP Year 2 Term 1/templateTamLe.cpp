#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

/*                 Mang                 */
template <typename T>
class Mang
{
public:
    Mang();
    Mang(T* data, int n);
    ~Mang();
    void sort();
    int timkiem(const T& key) const;
    void ghifile(const char* tenfile);
    void docfile(const char* tenfile);
    int timmax()const;
    int timmin()const;
    void xuat()const;
    void nhap();
    bool ktRong()const;
private:
    T* data;
    int n;
};

template <typename T>
Mang<T>::Mang() : data(NULL), n(0) {}

template <typename T>
Mang<T>::Mang(T* data, int n)
{
    this->data = new T[n];
    this->n = n;
    for (int i = 0; i < n; i++)
        this->data[i] = data[i];
}

template <typename T>
Mang<T>::~Mang()
{
    delete[] data;
}

template <typename T>
void Mang<T>::sort()
{
    std::sort(data, data + n);
}

template <typename T>
int Mang<T>::timkiem(const T& key) const
{
    for (int i = 0; i < n; i++)
        if (data[i] == key)
            return i;
    return -1;
}

template <typename T>
void Mang<T>::ghifile(const char* tenfile)
{
    ofstream fout(tenfile);
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << data[i] << endl;
    fout.close();
}

template <typename T>
void Mang<T>::docfile(const char* tenfile)
{
    ifstream fin(tenfile);
    fin >> n;
    data = new T[n];
    for (int i = 0; i < n; i++)
        fin >> data[i];
    fin.close();
}

template <typename T>
int Mang<T>::timmax()const
{
    if (n == 0) return -1;

    int index = 0;
    T max = data[0];

    for (int i = 1; i < n; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
            index = i;
        }
    }

    return index;
}

template <typename T>
int Mang<T>::timmin()const
{
    if (n == 0) return -1;

    int index = 0;
    T min = data[0];

    for (int i = 1; i < n; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
            index = i;
        }
    }

    return index;
}

template <typename T>
void Mang<T>::xuat()const
{
    for (int i = 0; i < n; i++)
        cout << data[i] << endl;
}

template <typename T>
void Mang<T>::nhap()
{
    cout << "Nhap so phan tu: ";
    cin >> n;
    data = new T[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ":" << std::endl;
        cin >> data[i];
    }
}

template <typename T>
bool Mang<T>::ktRong()const
{
    return n == 0;
}

/*                 HocSinh                 */
class Hocsinh
{
public:
    Hocsinh();
    Hocsinh(char hoten1[], int tuoi, float dtb);
    friend ostream& operator << (ostream& os, Hocsinh& r);
    friend istream& operator >> (istream& is, Hocsinh& r);
    bool operator > (Hocsinh& r) const;
    bool operator < (const Hocsinh& r) const;
    bool operator == (const Hocsinh& r) const;
    friend void sapxep(Hocsinh a[], int n);
private:
    char hoten[55];
    int tuoi;
    float dtb;
};

Hocsinh::Hocsinh() : tuoi(0), dtb(0)
{
    strcpy(hoten, "");
}

Hocsinh::Hocsinh(char hoten1[], int tuoi, float dtb) : tuoi(tuoi), dtb(dtb)
{
    strcpy(hoten, hoten1);
}

bool Hocsinh::operator > (Hocsinh& r) const
{
    return tuoi > r.tuoi;
}

bool Hocsinh::operator < (const Hocsinh& r) const
{
    return tuoi < r.tuoi;
}

bool Hocsinh::operator == (const Hocsinh& r) const
{
    return tuoi == r.tuoi;
}

ostream& operator << (ostream& os, Hocsinh& r)
{
    os << r.hoten << endl;
    os << r.tuoi << " " << r.dtb;
    return os;
}

istream& operator >> (istream& is, Hocsinh& r)
{
    is.getline(r.hoten, 55); // clear buffer
    is.getline(r.hoten, 55);
    is >> r.tuoi >> r.dtb;
    char tmp[1];
    return is;
}

void sapxep(Hocsinh a[], int n)
{
    std::sort(a, a + n);
}

/*                 main                 */
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
