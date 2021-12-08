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

class Mammal {
public:
    Mammal();
    virtual ~Mammal();

    virtual void move();
    virtual void speak();

protected:
    int itsAge;
};

Mammal::Mammal() :itsAge(1) {
    cout << "Mammal constructor..." << endl;
}

Mammal::~Mammal() {
    cout << "Mammal destructor..." << endl;
}

void Mammal::move() {
    cout << "Mammal moves a step!" << endl;
}

void Mammal::speak() {
    cout << "What does a mammal speak ? Mammilian " << endl;
}

class Cat :public Mammal {
public:
    Cat() :Mammal() {
        cout << "Cat constructor..." << endl;
    }
    ~Cat() {
        cout << "Cat destructor..." << endl;
    }
    void speak() {
        cout << "What does a Cat say ? Meow " << endl;
    }
};
class Horse :public Mammal {
public:
    Horse() :Mammal() {
        cout << "Horse constructor..." << endl;
    }
    ~Horse() {
        cout << "Horse destructor..." << endl;
    }
    void speak() {
        cout << "What does a Horse say ? Ney! " << endl;
    }
};
class GuineaPig :public Mammal {
public:
    GuineaPig() :Mammal() {
        cout << "GuineaPig constructor..." << endl;
    }
    ~GuineaPig() {
        cout << "GuineaPig destructor..." << endl;
    }
    void speak() {
        cout << "What does a GuineaPig say ? Wheep WHEEP! " << endl;
    }
};
class Dog :public Mammal {
public:
    Dog() :Mammal() {
        cout << "Dog constructor..." << endl;
    }
    ~Dog() {
        cout << "Dog destructor..." << endl;
    }
    void speak() {
        cout << "What does a Dog say ? Woof " << endl;
    }
};

int main() {


    Mammal* theArray[5];
    Mammal* ptr;
    int choice;
    for (int i = 0; i < 5; i++) {
        cout << "(1)dog (2)cat (3)horse (4)guinea pig:";
        cin >> choice;
        switch (choice) {
        case 1:ptr = new Dog;
            break;
        case 2:ptr = new Cat;
            break;
        case 3:ptr = new Horse;
            break;
        case 4:ptr = new GuineaPig;
            break;
        default:ptr = new Mammal;
            break;
        }
        theArray[i] = ptr;
    }
    for (int i = 0; i < 5; i++) {
        theArray[i]->speak();
    }
    for (int i = 0; i < 5; i++) {
        delete theArray[i];
    }
    return 0;
}