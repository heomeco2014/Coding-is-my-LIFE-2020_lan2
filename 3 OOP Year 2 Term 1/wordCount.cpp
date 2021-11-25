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

int main() {
    int wordCount = 1;
    cout << "Please input your string here" << endl;
    string inputString;
    getline(cin, inputString);
    for (int i = 0; i < inputString.size(); i++)
    {
        if (inputString[i] == ' ' && inputString[i + 1] != ' ')
        {
            wordCount++;
        }
    }
    cout << wordCount;
    return 0;
}