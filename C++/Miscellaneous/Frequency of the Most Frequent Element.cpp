#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        int l = 0, r = 0, result = 0;
        long currSum = 0;

        for (r = 0; r < nums.size(); r++)
        {
            currSum += nums[r];
            long target = nums[r];
            while ((r - l + 1) * target - currSum > k)
            {
                currSum -= nums[l];
                l++;
            }
            result = max(r - l + 1, result);
        }

        return result;
    }
};