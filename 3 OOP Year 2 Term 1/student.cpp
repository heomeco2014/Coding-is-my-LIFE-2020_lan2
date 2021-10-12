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

class student {
private:
    string studentName, studentAddress;
    double studentMathScore, studentLitScore;

public:
    void input() {
        cout << "Input name stu ";
        getline(cin, studentName);
        cout << "Input address stu ";
        getline(cin, studentAddress);
        cout << "Input mathScore ";
        cin >> studentMathScore;
        cout << "Input studentLitScore ";
        cin >> studentLitScore;
    }
    void print();
};

void student::print() {
    cout << "Name " << studentName;
    cout << "Address  " << studentAddress << endl;
    cout << "Math Score " << studentMathScore << endl;
    cout << "Lit Score " << studentLitScore << endl;
}

int main() {

    student nhatMinh;
    nhatMinh.input();
    nhatMinh.print();
    return 0;
}