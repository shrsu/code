#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        if (n == h)
        {
            return *max_element(piles.begin(), piles.end());
        }

        int max_piles = *max_element(piles.begin(), piles.end());
        int min_speed = 1;
        int max_speed = max_piles;

        while (min_speed < max_speed)
        {
            int mid_speed = min_speed + (max_speed - min_speed) / 2;
            if (canEatAll(piles, h, mid_speed))
            {
                max_speed = mid_speed;
            }
            else
            {
                min_speed = mid_speed + 1;
            }
        }
        return min_speed;
    }

private:
    bool canEatAll(const vector<int> &piles, int h, int speed)
    {
        int hours = 0;
        for (int bananas : piles)
        {
            hours += (bananas + speed - 1) / speed;
        }
        return hours <= h;
    }
};