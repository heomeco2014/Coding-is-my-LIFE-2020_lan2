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
class soPhuc {
private:
    double phanThuc, phanAo;

public:
    soPhuc() {
        phanThuc = 0;
        phanAo = 0;
    }
    soPhuc(int thuc, int ao) {
        phanThuc = thuc;
        phanAo = ao;
    }
    soPhuc operator+(const soPhuc &sp) {
        soPhuc rt = *this;
        rt.phanThuc += sp.phanThuc;
        rt.phanAo += sp.phanAo;
        return rt;
    }
    soPhuc operator-(const soPhuc &sp) {
        soPhuc rt = *this;
        rt.phanThuc -= sp.phanThuc;
        rt.phanAo -= sp.phanAo;
        return rt;
    }
    soPhuc operator*(const soPhuc &sp) {
        soPhuc c = *this;
        c.phanThuc = phanThuc * sp.phanThuc - phanAo * sp.phanAo;
        c.phanAo = phanThuc * sp.phanAo + phanAo * sp.phanThuc;
        return c;
    }
    void printSoPhuc() {
        cout << this->phanThuc << " " << this->phanAo << "i" << endl;
    }
};
int main() {
    soPhuc s1(4, 2);
    soPhuc s2(5, 3);
    soPhuc s3 = s1 + s2;
    s3.printSoPhuc();
    soPhuc s4 = s1 - s2;
    s4.printSoPhuc();
    soPhuc s5 = s1 * s2;
    s5.printSoPhuc();
    return 0;
}