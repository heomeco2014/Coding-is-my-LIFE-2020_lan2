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

class MyString {
private:
    string str;
public:
    MyString() :str("") {}
    MyString(const string& str) {
        this->str = str;
    }

    MyString Split(vector<MyString> arrChar, bool isDelSpace) {
        size_t pos_start = 0, pos_end, delim_len = arrChar.size();
        string token;
        vector<string> res;

        while ((pos_end = str.find(arrChar, pos_start)) != string::npos) {
            token = str.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(str.substr(pos_start));
        return res;
    }
    MyString operator +(const MyString& newStr) {
        MyString res;
        res.str = this->str + newStr.str;
        return res;
    }
    friend MyString operator +(const string& newStr, const MyString& str2) {
        MyString res;
        res.str = newStr + str2.str;
        return res;
    }

    friend ostream& operator<<(ostream& os, const MyString& str) {
        os << str.str;
        return os;
    }
};
int main() {
    MyString ms1("abcdsf");
    MyString ms2 = "____" + ms1;
    MyString ms3 = ms1 + ms2;
    cout << "ms1= " << ms1 << endl;
    cout << "ms2= " << ms2 << endl;
    cout << "ms3= " << ms3 << endl << endl;
    return 0;
}