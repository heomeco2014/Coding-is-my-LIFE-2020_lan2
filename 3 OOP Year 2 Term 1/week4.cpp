#include <iostream>
#include <typeinfo>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
class cFraction {
private:
    int tu, mau;
public:
    cFraction() :tu(0), mau(1) {}
    cFraction(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
        simplify();
    }

    void simplify() {
        int UCLN = gcd(abs(this->tu), abs(this->mau));
        this->tu /= UCLN;
        this->mau /= UCLN;
        if (this->tu < 0 && this->mau < 0) {
            this->tu = abs(this->tu);
            this->mau = abs(this->mau);
        }
        else if (this->tu > 0 && this->mau < 0) {
            this->tu *= -1;
            this->mau = abs(this->mau);
        }
    }
    void print() {
        cout << this->tu << "/" << this->mau << endl;
    }
    operator string() {
        string str = "";
        str += to_string(tu);
        if (to_string(mau) != "1") {
            str += "/" + to_string(mau);
        }
        return str;
    }

    cFraction& operator++() {
        this->tu += this->mau;
        return *this;
    }
    cFraction operator++(int) {
        cFraction copyObject(*this);
        this->tu += this->mau;
        return copyObject;
    }

    cFraction operator+(const cFraction& other) {
        cFraction d;
        d.tu = d.tu * other.mau + d.mau * other.tu;
        d.mau = d.mau * other.mau;
        d.simplify();
        return d;
    }
    cFraction operator*(const cFraction& other) {
        this->tu = this->tu * other.tu;
        this->mau = this->mau * other.mau;
        this->simplify();
        return *this;
    }
    cFraction operator ()(int n) {
        cFraction p(1, 1);
        for (int i = 0; i < n; i++)
        {
            p = p * *this;
        }
        p.simplify();
        return p;
    }
};

int main() {
    cFraction a(2, 3), b(3, 4), c;
    c = a + b;
    cout << string(c) << endl;
    cout << string(a(5)) << endl;
    return 0;
}