#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> array = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<int> secondArray = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < array.size(); i++) {
        for (int number : array[i]) {
            cout << number;
        }
        cout << endl;
    }

    for (int x : secondArray) {
        cout << x << " ";
    }
}