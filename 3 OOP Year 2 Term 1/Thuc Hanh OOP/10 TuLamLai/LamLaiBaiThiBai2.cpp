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

class SoNguyen
{
private:
    int v;
public:
    SoNguyen() :v(0) {}
    SoNguyen(int val) :v(val) {};
    int getValue() { return v; };
    bool operator>(const SoNguyen& sn) {
        return v > sn.v;
    }
    bool operator<(const SoNguyen& sn) {
        return v < sn.v;
    }

    friend ostream& operator<<(ostream& os, const SoNguyen& sn) {
        os << sn.v;
        return os;
    }
    friend istream& operator>>(istream& is, SoNguyen& sn) {
        is >> sn.v;
        return is;
    }
};

int main() {
    srand(time(0));
    int n;
    cout << "Nhap so luong mang ";
    cin >> n;
    SoNguyen* sn = new SoNguyen[n];
    for (int i = 0; i < n; i++)
    {
        sn[i] = rand() % n + 1;
    }
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cout << sn[i] << " ";
        if (sn[i] < min) {
            min = sn[i].getValue();
        }
    }
    cout << "Nho nhat " << min;


    return 0;
}