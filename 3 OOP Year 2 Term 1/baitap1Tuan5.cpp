#include<iostream>
using namespace std;

// class Human {
// private:
//     int Age;
//     string Name;
// public:
//     Human(string InputName, int InputAge) {
//         Name = InputName;
//         Age = InputAge;
//     }
//     friend void DisplayAge(const Human* Person);
// };

// void DisplayAge(const Human* Person) {
//     cout << Person->Age << endl;
// }
// int main() {
//     Human* pTom = new Human("Minh", 20);
//     DisplayAge(pTom);

// }


class Base
{
private:

public:
    void test();
    void test(int);
    void test(int, int);
};
void Base::test() {
    cout << "test 0 parameter run" << endl;
}
void Base::test(int x) {
    cout << "test 1 parameter run" << endl;
}

void Base::test(int x, int y) {
    cout << "test 2 parameter run" << endl;
}

class Derive :public Base {
public:
    void test(int);
};
void Derive::test(int x) {   
    cout << "test of Derived 1 parameter run" << endl;
}

int main() {
    Derive obj;
    obj.test(2);
    obj.Base::test(2, 3);
    return 0;
}