#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    void helper(vector<vector<int>> &ans, vector<int> candidates,
                vector<int> temp, int target, int indx)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = indx; i < candidates.size(); i++)
        {
            if (i > indx && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (target < candidates[i])
            {
                break;
            }
            temp.push_back(candidates[i]);
            helper(ans, candidates, temp, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, candidates, temp, target, 0);
        return ans;
    }
};