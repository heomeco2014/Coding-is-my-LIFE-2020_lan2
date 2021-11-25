#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <ostream>
using namespace std;

class MyString {
private:
    string str;
public:
    static int count;
    MyString() {
        str = "";
    }
    MyString(string str) {
        this->str = str;
    }
    MyString(const char* charStr) {
        str = string(charStr);
    }
    friend MyString operator +(string tmp, const MyString& myString) {
        MyString a;
        a.str = tmp + myString.str;
        return a;
    }
    MyString operator +(const MyString& n) {
        MyString a;
        a.str = n.str + this->str;
        return a;
    }

    friend ostream& operator<<(ostream& os, const MyString& mstr) {
        os << mstr.str;
        return os;
    }
    vector<MyString> Split(vector<char> arrCh, bool isTrue) {
        vector <MyString> result;
        string const delims1 = { ".,;" };
        string const delims2 = { ".,;" };
        size_t beg, pos = 0;
        while ((beg = str.find_first_not_of(delims1, pos)) != string::npos && isTrue == true)
        {
            pos = str.find_first_of(delims1, beg + 1);
            MyString tmp = "" + str.substr(beg, pos - beg);
            result.push_back(tmp);
        }
        while ((beg = str.find_first_not_of(delims2, pos)) != string::npos && isTrue == false)
        {
            pos = str.find_first_of(delims2, beg + 1);
            MyString tmp = "" + str.substr(beg, pos - beg);
            result.push_back(tmp);
        }

        return result;
    }
};
int MyString::count = 0;
int main() {
    MyString ms1("abcdsf");
    MyString ms2 = "_____" + ms1;
    MyString ms3 = ms1 + ms2;
    cout << "ms1= " << ms1 << endl << "ms2= " << ms2 << endl << "ms3= " << ms3 << endl;
    MyString ms = "a,b,c;d.r;.,h;e,w__u,t.f;j_..";
    vector<char> arrChar;
    arrChar.push_back(',');
    arrChar.push_back('.');
    arrChar.push_back(';');
    vector<MyString> vMs = ms.Split(arrChar, false);
    cout << "Split: " << endl;
    for (vector<MyString>::iterator itMs = vMs.begin(); itMs != vMs.end();itMs++) {
        cout << *itMs << " ";
    }
    cout << endl << "size= " << vMs.size() << endl << endl;

    vMs = ms.Split(arrChar, true);
    cout << "Split co loai bo empty: " << endl;
    for (vector<MyString>::iterator itMs = vMs.begin(); itMs != vMs.end();itMs++) {
        cout << *itMs << " ";
    }
    cout << endl << "size= " << vMs.size() << endl << endl;
    return 0;
}