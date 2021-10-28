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

int* getBigInt(string str) {
    int x = str.size(), a = 0;
    int* arr = new int[x];
    while (x != a)
    {
        arr[a] = str[a] - '0';
        a++;
    }
    return arr;
}
class SoNguyenLon {
private:
    string num;
public:
    SoNguyenLon();
    SoNguyenLon(string num);
    SoNguyenLon(int theNum, int numTimes);
    friend int* getBigInt(string str);
    friend ostream& operator<<(ostream& os, const SoNguyenLon& soNguyen);
};
SoNguyenLon::SoNguyenLon() {
    this->num = "0";
}

SoNguyenLon::SoNguyenLon(string num) {
    this->num = num;
}

SoNguyenLon::SoNguyenLon(int theNum, int numTimes) {
    string res = "";
    for (int i = 0; i < numTimes; i++)
    {
        res += to_string(theNum);
    }
    this->num = res;
}

ostream& operator << (ostream& os, const SoNguyenLon& soNguyen) {
    os << soNguyen.num;
    return os;
}


int main() {
    // int* a = new int;
    // a = getBigInt("999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    // int* b = new int;
    // b = getBigInt("111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    SoNguyenLon a;
    cout << a << endl;
    SoNguyenLon b("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    cout << b << endl;
    SoNguyenLon c(3, 14);
    cout << c << endl;
    return 0;
}