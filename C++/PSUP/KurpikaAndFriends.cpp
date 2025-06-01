#include <bits/stdc++.h>

using namespace std;
int maxFriends(int n, vector<int> &s, vector<int> &e)
{

    map<int, int> numOfPeoples;
    for (int i = 0; i < n; i++)
    {
        numOfPeoples[s[i]]++;
        numOfPeoples[e[i] + 1]--;
    }
    int counter = 0;
    int mx = 0;

    map<int, int>::iterator itr = numOfPeoples.begin();

    while (itr != numOfPeoples.end())
    {
        counter += itr->second;
        mx = max(mx, counter);
        itr++;
    }
    return mx;
}
