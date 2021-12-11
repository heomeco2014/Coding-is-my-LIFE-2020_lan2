#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Hocsinh
{
private:
	char hoten[55];
	int tuoi;
	float dtb;
public:
	Hocsinh() :hoten(""), tuoi(0), dtb(0.0) {}
	Hocsinh(char hoten1[], int tuoi, float dtb)
	{
		strcpy_s(hoten, hoten1);
		this->tuoi = tuoi;
		this->dtb = dtb;
	}
	friend ostream& operator << (ostream& os, Hocsinh& r) {
		os << "TEN: " << r.hoten << ",TUOI: " << r.tuoi << ",DTB: " << r.dtb;
		return os;
	}
	friend istream& operator >> (istream& is, Hocsinh& r) {
			cout << "NHAP TEN HOC SINH " << endl;
			is.ignore();
			is.getline(r.hoten, 55);
			cout << "NHAP TUOI HOC SINH " << endl;
			is >> r.tuoi;
			cout << "NHAP DTB HOC SINH " << endl;
			is >> r.dtb;
		return is;
	}
	bool operator > (Hocsinh& r)
	{
		if (this->dtb > r.dtb)
		{
			return true;
		}
		return false;
	}
	bool operator < (const Hocsinh& r) {
		if (this->dtb < r.dtb)
		{
			return true;
		}
		return false;
	}
	friend void sapxep(Hocsinh a[], int n) {
	}
};

template <typename T>
class Mang
{
private:
	T* data;
	int n;
public:
	Mang() : data(NULL), n(0) {}
	Mang(T* data, int n) {
		this->data = data;
	}
	~Mang() {
		if (data != NULL)
		{
			delete[] data;
		}
	}
	void sort() {
		for (int i = 0; i < n - 1; i++)
			for (int j = n - 1; i < j; j--)
				if (data[j] < data[j - 1])
					swap(data[j], data[j - 1]);
	}
	int timkiem(const T& key) const {
		for (int i = 0; i < n; i++)
		{
			if (data[i] == key) {
				return i;
			}
		}
		return -1;
	}
	void ghifile(string tenfile) {
		ofstream writeToFile(tenfile);
		if (writeToFile.is_open())
		{
			for (int i = 0; i < n; i++)
			{
				writeToFile << data[i];
				if (i != n - 1)
				{
					writeToFile << endl;
				}
			}
		}
		writeToFile.close();
	}
	void docfile(string tenfile) {}
	int timmax()const {
		int maxE = INT_MIN;
		int pos = -1;
		for (int i = 0; i < n; i++)
		{
			if (data[i] > maxE) {
				maxE = data[i];
				pos = i;
			}
		}
		return pos;
	}
	int timmin()const {
		int minE = INT_MAX;
		int pos = -1;
		for (int i = 0; i < n; i++)
		{
			if (data[i] < minE) {
				minE = data[i];
				pos = i;
			}
		}
		return pos;
	}
	void nhap() {
		do {
			cout << "NHAP SO LUONG PHAN TU : " << endl;
			cin >> n;
		} while (n <= 0 && cout << "NHAP LAI SO LUONG PHAN TU " << endl);

		data = new T[n];
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
		}
	}
	void xuat()const {
		for (int i = 0; i < n; i++)
		{
			cout << data[i] << " ";
			cout << endl;
		}
	}
	bool ktRong()const {
		if (data == NULL)	return true;
		return false;
	}
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