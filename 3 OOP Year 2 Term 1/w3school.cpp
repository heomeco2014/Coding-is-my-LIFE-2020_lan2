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

class Vehicle {
  public:
    // string brand = "Ford";
    void honk() {
      cout << "Tuut, tuut! \n" ;
    }
};

class Car{
public:
    string brand;
    string model;
    int year;
    Car(string x, string y, int z);
};
// Constructor definion outside of a class
Car::Car(string x, string y, int z) {
    brand = x;
    model = y;
    year = z;
}

int main() {

    Car carObj1("BMW", "X5", 1999);
    Car carObj2("Ford", "Mustang", 1969);

    cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << endl;

    return 0;
}