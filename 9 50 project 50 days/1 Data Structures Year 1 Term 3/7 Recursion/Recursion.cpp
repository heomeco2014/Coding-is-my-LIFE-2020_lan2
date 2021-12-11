#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
typedef long long ll;
using namespace std;

//1 Sum of 1 + 2 + .. n
ll sumOfS(int n)
{
    if (n == 0)
        return 0;
    return n + sumOfS(n - 1);
}

ll calcFactorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * calcFactorial(n - 1);
}
// calc x^n
ll myPow(int x, int n)
{
    if (n == 1)
        return x;
    return myPow(x * x, n - 1);
}
// count the number of digit
int countNumOfdigit(int n, int count = 0)
{
    if (n == 0)
        return count;
    return countNumOfdigit(n / 10, count + 1);
}

bool isEveryDigitEven(int n)
{
    if (n == 0)
        return true;
    else if (n % 2 != 0)
        return false;
    else
        return isEveryDigitEven(n / 10);
}
//8
ll calcReverseValue(int n, int result = 0)
{
    if (n == 0)
        return result;
    return calcReverseValue(n / 10, result * 10 + n % 10);
}

int main()
{
    cout << sumOfS(3);
    cout << endl;
    cout << calcFactorial(11);
    cout << endl;
    cout << myPow(5, 1);
    cout << endl;
    cout << countNumOfdigit(2000);
    cout << endl;
    cout << isEveryDigitEven(26);
    cout << endl;
    cout << calcReverseValue(25);
    return 0;
}