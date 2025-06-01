#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &result)
{
    result.push_back(path);
    for (int i = start; i < nums.size(); ++i)
    {
        if (i > start && nums[i] == nums[i - 1])
            continue;
        path.push_back(nums[i]);
        backtrack(nums, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> path;
    sort(nums.begin(), nums.end());
    backtrack(nums, 0, path, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    for (const auto &subset : result)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
