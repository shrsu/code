#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> keys = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Helper function for recursion
void helper(int a[], int n, string temp, int indx, vector<string> &ans)
{
    if (indx == n)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < keys[a[indx]].size(); i++)
    {
        helper(a, n, temp + keys[a[indx]][i], indx + 1, ans);
    }
}

// Main function to get all combinations
vector<string> possibleWords(int a[], int n)
{
    vector<string> ans;
    helper(a, n, "", 0, ans);
    return ans;
}

int main()
{
    string s;

    cout << "Enter phone number: ";
    cin >> s;

    int a[s.size()];
    for (int i = 0; i < s.size(); i++)
    {
        a[i] = s[i] - '0';
    }

    vector<string> ans = possibleWords(a, s.size());

    cout << "Letter Combinations: \n";
    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}
