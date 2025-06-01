#include <iostream>
using namespace std;

class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        long right = n - index - 1;
        long left = index;

        long hi = maxSum;
        long lo = 1;

        long int ans = 0;

        while (lo <= hi)
        {
            long mid = (hi - lo) / 2 + lo;
            long sum = mid;
            long rsum = 0;
            long lsum = 0;
            long m = mid - 1;

            if (right <= m)
            {
                rsum = m * (m + 1) / 2 - (m - right) * (m - right + 1) / 2;
            }
            else
            {
                rsum = m * (m + 1) / 2 + (right - m);
            }

            if (left <= m)
            {
                lsum = m * (m + 1) / 2 - (m - left) * (m - left + 1) / 2;
            }
            else
            {
                lsum = m * (m + 1) / 2 + (left - m);
            }

            sum += (lsum + rsum);

            if (sum <= maxSum)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }
};