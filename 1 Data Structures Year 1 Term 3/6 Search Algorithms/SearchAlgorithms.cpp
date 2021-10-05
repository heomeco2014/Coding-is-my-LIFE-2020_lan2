#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

int binarySearch(int *a, int left, int right, int target)
{
    int mid = (left + right) / 2;
    if (a[mid] == target)
        return mid;
    else if (a[mid] > target)
        return binarySearch(a, left, mid - 1, target);
    else
        return binarySearch(a, mid + 1, right, target);
}


int binarySearch(int *a, int target, int n)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] > target)
        {
            right = mid-1;
        }
        else left = mid+1;
    }
    return -1;
}
int linearSearch(int*a, int n, int key){
    int flag = -1;
    for (size_t i = 0; i < n; i++)
    {
        if(a[i]==key) {
            flag = i;
            break;
        }
    }
    return flag;
}

int main()
{
    // int size = 5;
    // int *a = {new int[size]{0, 1, 2, 5, 6}};

    // cout << binarySearch(a, 0, 4, 5);
    // cout << endl;
    // cout << binarySearch(a,5,5);
    // cout << endl;
    // cout << linearSearch(a,5,5);

    
    return 0;
}