#include <iostream>
#include <vector>

using namespace std;

bool find(vector<int> nums, int target, int indx)
{
    if (target == 0)
    {
        return true; 
    }
    if (indx >= nums.size() || target < 0)
    {
        return false; 
    }

    bool include = find(nums, target - nums[indx], indx + 1);

    bool exclude = find(nums, target, indx + 1);

    return include || exclude;
}

bool isPresent(vector<int> &nums)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    return find(nums, sum / 2, 0);
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};
    if (isPresent(nums))
    {
        cout << "There exists a subset with the given sum" << endl;
    }
    else
    {
        cout << "No subset with the given sum exists" << endl;
    }
    return 0;
}
