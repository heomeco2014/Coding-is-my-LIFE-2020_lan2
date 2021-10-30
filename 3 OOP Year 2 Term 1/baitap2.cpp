#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
using namespace std;

long long* getBigInt(string str) {
    long long x = str.size(), a = 0;
    long long* arr = new long long[x];
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
    SoNguyenLon(long long num);
    SoNguyenLon(long long theNum, long long numTimes);
    friend SoNguyenLon operator-(const SoNguyenLon& sn);
    friend SoNguyenLon operator-(const SoNguyenLon& sn1, const SoNguyenLon& sn2);
    friend SoNguyenLon operator-(const long long& integers, const SoNguyenLon& sn);
    friend long long* getBigInt(string str);
    friend ostream& operator<<(ostream& os, const SoNguyenLon& soNguyen);
};
SoNguyenLon::SoNguyenLon() {
    this->num = "0";
}

SoNguyenLon::SoNguyenLon(long long num) {
    this->num = to_string(num);
}

SoNguyenLon::SoNguyenLon(long long theNum, long long numTimes) {
    string res = "";
    for (long long i = 0; i < numTimes; i++)
    {
        res += to_string(theNum);
    }
    this->num = res;
}
SoNguyenLon operator-(const SoNguyenLon& sn) {
    SoNguyenLon d;
    long long tmp = stoi(d.num);
    long long tmp2 = stoi(sn.num);
    return tmp + tmp2;
}

SoNguyenLon operator-(const long long& integers, const SoNguyenLon& sn) {
    return integers - stoi(sn.num);
}
vector <long long> integerToArray(long long x)
{
    vector <long long> resultArray;
    while (true)
    {
        resultArray.insert(resultArray.begin(), x % 10);
        x /= 10;
        if (x == 0)
            return resultArray;
    }
}
SoNguyenLon operator-(const SoNguyenLon& sn1, const SoNguyenLon& sn2) {
    // long long first, second;
    // first = stoi(sn1.num);
    // second = stoi(sn2.num);
    // vector<long long> tmp1, tmp2;
    // tmp1 = integerToArray(first);
    // tmp2 = integerToArray(second);
    // vector<long long> result;
    // for (long long i = sn2.num.size(); i >= 0; i--) {
    //     long long soNho = 0;
    //     long long temp = tmp1[i] + tmp2[i];
    //     if (temp > 10) {
    //         temp %= 10;
    //         soNho = 1;
    //         result.insert(result.begin(), temp);
    //     }
    // }
    SoNguyenLon ketQua;
    int* t1 = new int[sn1.num.size()];
    int* t2 = new int[sn2.num.size()];
    for (int i = 0; i < sn1.num.size(); i++)
    {
        t1[i] = sn1.num[i];
    }
    for (int i = 0; i < sn2.num.size(); i++)
    {
        t2[i] = sn2.num[i];
    }
    int nho = 0;
    vector<int> res;
    for (int i = sn1.num.size();i >= 0; i--) {
        int rightNow = t1[i] - t2[i] - nho;

        if (rightNow < 0) {
            rightNow = -rightNow;
            nho = 1;
        }
        cout << rightNow << endl;
        res.insert(res.begin(), rightNow);
    }




    return ketQua;
}

ostream& operator << (ostream& os, const SoNguyenLon& soNguyen) {
    os << soNguyen.num;
    return os;
}

int main() {

    SoNguyenLon snl1;
    SoNguyenLon snl2(1234567);
    SoNguyenLon snl3(3, 14);
    SoNguyenLon snl4(9, 20);
    SoNguyenLon t1(23), t2(23);
    SoNguyenLon snl5 = t1 - t2;
    // SoNguyenLon snl6 = 45678910 - snl2;

    cout << snl1 << endl << snl2 << endl << snl3 << endl << snl4 << endl << snl5 << endl;
    return 0;
}