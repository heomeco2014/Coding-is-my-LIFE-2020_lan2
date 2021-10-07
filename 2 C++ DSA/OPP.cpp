#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee
{
private:
    string Name;
    string Company;
    int Age;

public:
    void IntroduceSelf()
    {
        cout << "I'm " << Name << endl;
        cout << "I work for " << Company << endl;
        cout << "My age is: " << Age << endl;
    }
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
    // Setter & Getter
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setAge(int age)
    {
        Age = age;
    }
    int getAge() { return Age; }
    void AskForPromotion(){
        if(Age > 30) cout << Name << " got promoted" << endl;
        else cout << Name << " NOT promotion" << endl;
    }
};

class chessTeacher:Employee{
    
};

int main()
{
    Employee employ1 = Employee("Nhat Minh", "VN Chess", 31);

    employ1.AskForPromotion();
    return 1;
}