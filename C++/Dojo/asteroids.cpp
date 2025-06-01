#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> findAsteroids(vector<int> asteroids)
{
    int n = asteroids.size();

    if (n < 1)
    {
        return {};
    }

    stack<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push(asteroids[i]);
        while (ans.size() >= 2)
        {
            int temp = ans.top();
            ans.pop();

            if (ans.top() <= 0 && temp > 0)
            {
                ans.push(temp);
                break;
            }

            else if (ans.top() > 0 && temp < 0)
            {
                if (abs(temp) > ans.top())
                {
                    ans.pop();
                    ans.push(temp);
                }
                else if (abs(temp) == ans.top())
                {
                    ans.pop();
                }
            }

            else
            {
                ans.push(temp);
                break;
            }
        }
    }

    vector<int> finalAns;
    while (!ans.empty())
    {
        finalAns.push_back(ans.top());
        ans.pop();
    }
    reverse(finalAns.begin(), finalAns.end());
    return finalAns;
}

int main()
{
    int n;
    cin >> n;
    int a;
    vector<int> asteroids;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        asteroids.push_back(a);
    }

    vector<int> ans = findAsteroids(asteroids);

    for (auto i : asteroids)
    {
        cout << i << " ";
    }
}