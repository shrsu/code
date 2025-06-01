#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backTrack(vector<vector<int>> &ans, vector<int> nums, int indx)
{
    if (indx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = indx; i < nums.size(); i++)
    {
        swap(nums[i], nums[indx]);
        backTrack(ans, nums, indx + 1);
        swap(nums[i], nums[indx]);
    }
}
vector<vector<int>> findPerms(vector<int> nums)
{
    vector<vector<int>> ans;
    backTrack(ans, nums, 0);
    return ans;
}

int main()
{
    int n, a;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }

    vector<vector<int>> ans = findPerms(nums);
    cout << ans.size();
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << '\n';
    }
}