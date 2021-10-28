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
class Animal {
public:
    void eat() {
        cout << name << " can eat " << endl;
    }
    void sleep() {
        cout << name << " can sleep " << endl;
    }
    Animal(){};
    Animal(string animalName, int animalCapacity) {
        this->name = animalName;
        this->capacity = animalCapacity;
    }

protected:
    string name;
    int capacity;
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Hello";
    }
    Dog() : Animal("Tino", 12){};
};
int main() {

    Animal CPlusPlus("Tino", 18);
    CPlusPlus.eat();
    CPlusPlus.sleep();

    Dog CSharp;
    CSharp.eat();
    return 0;
}