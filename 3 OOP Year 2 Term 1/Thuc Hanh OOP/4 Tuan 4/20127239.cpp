#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
#include <algorithm>  
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
    // friend SoNguyenLon operator-(const SoNguyenLon& sn);
    friend SoNguyenLon operator-(const SoNguyenLon& sn1, const SoNguyenLon& sn2);

    friend SoNguyenLon operator-(const long long& integers, const SoNguyenLon& sn);
    friend vector<long long> integerToArray(const SoNguyenLon& x) {
        vector<long long> res;
        for (int i = 0; i < x.num.size(); i++)
        {
            res.push_back(x.num[i] - '0');
        }
        return res;
    };
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


SoNguyenLon operator-(const long long& integers, const SoNguyenLon& sn) {
    return integers - stoi(sn.num);
}

SoNguyenLon operator-(const SoNguyenLon& sn1, const SoNguyenLon& sn2) {
    SoNguyenLon res;
    vector<long long> first, second, result;
    first = integerToArray(sn1);
    second = integerToArray(sn2);
    int fSize = sn1.num.size();
    int tmpSize = sn1.num.size();
    int sSize = sn2.num.size();
    int nho = 0;
    while (fSize != 0 && sSize != 0)
    {
        int temp = first[fSize] - second[sSize] - nho;
        if (temp < 0) {
            temp = first[fSize] + 10 - second[sSize] - nho;
            nho = 1;
        }
        fSize--;
        sSize--;
        result.push_back(temp);
    }
    while (fSize != 0)
    {
        result.push_back(first[fSize]);
        fSize--;
    }

    res.num = "";
    for (int i = tmpSize; i >= 0; i--)
    {
        res.num += result[i] + '0';
    }
    // for (int i = 0; i < sn1.num.size(); i++)
    // {
    //     cout << first[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < sn2.num.size(); i++)
    // {
    //     cout << second[i] << " ";
    // }
    cout << endl;
    return res;

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
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 45678910 - snl2;
    // SoNguyenLon snl7 = snl4 - snl3 + 123456789;


    cout << snl1 << endl << snl2 << endl << snl3 << endl << snl4 << endl << snl5 << endl;
    return 0;
}