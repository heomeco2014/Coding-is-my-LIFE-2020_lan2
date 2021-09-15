#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include<algorithm>
typedef long long ll;
using namespace std;

class Solution
{
public:
    //O(n^2) approach
    int maxSubArray(vector<int> &nums)
    {
        ll max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            ll sum = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                sum += nums[j];
                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }
};

class Solution
{
public:
    //O(n) approach
    int maxSubArray(vector<int> &nums)
    {
        int Max = nums[0];
        int thisMax = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            thisMax = max(thisMax+nums[i],nums[i]);
            Max = max(Max,thisMax);
        }
        return Max;
    }
};
int main()
{

    return 0;
}