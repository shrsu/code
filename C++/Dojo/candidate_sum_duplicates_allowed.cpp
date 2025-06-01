#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }

private:
    void findComb(int indx, int target, vector<int> candidates,
                  vector<vector<int>> &ans, vector<int> &ds)
    {
        if (indx == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (candidates[indx] <= target)
        {
            ds.push_back(candidates[indx]);
            findComb(indx, target - candidates[indx], candidates, ans, ds);
            ds.pop_back();
        }

        findComb(indx + 1, target, candidates, ans, ds);
    }
};