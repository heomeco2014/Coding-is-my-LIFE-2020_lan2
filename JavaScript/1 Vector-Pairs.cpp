#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> arr, int sum) {
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        int x = sum - arr[i];
        if (s.find(x) != s.end()) {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        s.insert(arr[i]);
    }
    return {};
}
int main() {

    //Fill constructor
    // vector<int> arr(10, 8); // 10 elements with value of 8
    // for (int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }

    // 2D vector
    // vector<vector<int>> arr = {
    //     {1, 2, 3},
    //     {4, 5, 6, 10, 11, 12},
    //     {7, 8, 9}};
    // for (int i = 0; i < arr.size(); i++) {
    //     for (int j = 0; j < arr[i].size(); j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Pairs
    vector<int> arr{10, 5, 2, 3, -6, 9, 11};
    int sum = 4;

    auto p = pairSum(arr, sum);

    if (p.size() == 0)
        cout << "No such pair";
    else
        cout << p[0] << " " << p[1] << endl;
    return 0;
}
