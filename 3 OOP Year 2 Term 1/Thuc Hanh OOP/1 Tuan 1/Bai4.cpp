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
class MangSoNguyen {
private:
    int size, arr[];

public:
    void xuat()
    {
        for (int i = 0; i < this->size; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
    MangSoNguyen()
    {
        size = 0;
    };
    MangSoNguyen(int a)
    {
        size = a;
    }
    MangSoNguyen(int a[], int size)
    {
        this->size = size;
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = a[i];
        }
    }
    MangSoNguyen(const MangSoNguyen& coppy)
    {
        size = coppy.size;
        for (int i = 0; i < coppy.size; i++) {
            this->arr[i] = coppy.arr[i];
        }
    }
};
int main()
{
    MangSoNguyen msn1;
    msn1.xuat();
    MangSoNguyen msn2(5);
    msn2.xuat();
    int arr[10];
    for (int i = 0; i < 8; i++) {
        arr[i] = i * i;
    }

    MangSoNguyen msn3(arr, 8);
    msn3.xuat();

    MangSoNguyen msn4(msn3);
    msn4.xuat();
    return 0;
}