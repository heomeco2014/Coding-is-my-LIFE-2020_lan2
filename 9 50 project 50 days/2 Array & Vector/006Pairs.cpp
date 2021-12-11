#include <iostream>
#include <vector>
using namespace std;
/*
   Given an array containnig N integers, and a number S denoting a target Sum
   Find two distinct integers that can pair up to form target sum. Let us assume there will be only one such pair
   Input:
   array = [10,5,2,3,-6,9,11]
   S = 4
   Output: 
   [10,-6] 
*/
int main() {
    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    int sum = 4;
    int a{0}, b{0};

    // Cach nay O(N^2)
    // for (int i = 0; i < arr.size(); i++) {
    //     for (int j = i + 1; j < arr.size(); j++) {
    //         if (arr[i] + arr[j] == sum) {
    //             a = arr[i];
    //             b = arr[j];
    //             break;
    //         }
    //     }
    // }

    
    cout << a << " " << b;
    return 0;
}
