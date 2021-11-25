#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <istream>
#include <iomanip>
#include <climits>
#include <stdio.h>      
#include <stdlib.h>   
#include <time.h>  
using namespace std;

class SoNguyen
{
private:
    int v;
public:
    SoNguyen(); // Tạo ra một giá trị có giá trị bằng 0
    SoNguyen(int val); // Tạo ra một đối tượng có giá trị xác định
    int getValue(); // Trả về giá trị trong đối tượng

    friend bool operator>(const SoNguyen& other, const SoNguyen& other2) {
        return other.v > other2.v;
    }
    friend bool operator<(const SoNguyen& other, const SoNguyen& other2) {
        return other.v < other2.v;
    }
    friend ostream& operator << (ostream& os, const SoNguyen& sn) {
        os << sn.v;
        return os;
    }
    friend istream& operator >> (istream& is, SoNguyen& sn) {
        cout << "Moi thay nhap so: " << endl;
        is >> sn.v;
        return is;
    }

};
SoNguyen::SoNguyen() {
    v = 0;
}
SoNguyen::SoNguyen(int val) {
    v = val;
}
int SoNguyen::getValue() {
    return v;
}

int main() {
    SoNguyen sn1;
    SoNguyen sn2(2);
    SoNguyen array[50];
    int min = INT_MAX;
    int high = 50;
    int low = 0;
    srand(10);
    for (size_t i = 1; i < 50; i++)
    {
        array[i] = rand() % (high - low + 1) + low;
    }
    for (size_t i = 1; i < 50; i++)
    {
        if (array[i].getValue() < min) min = array[i].getValue();
    }

    cout << "Gia tri nho nhat la " << min << endl;
    return 0;
}