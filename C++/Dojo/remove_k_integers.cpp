#include <iostream>
#include <string>

using namespace std;

string removeKdigits(string num, int k)
{
    string ans = "";
    for (char c : num)
    {
        while (ans.size() && ans.back() > c && k)
        {
            ans.pop_back();
            k--;
        }
        if (ans.size() || c != '0')
            ans.push_back(c);
    }
    while (ans.size() && k--)
    {
        ans.pop_back();
    }
    return (ans == "") ? "0" : ans;
}

int main()
{
    string num;
    int k;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the number of digits to remove: ";
    cin >> k;

    string result = removeKdigits(num, k);

    cout << "Number after removing " << k << " digits: " << result << endl;

    return 0;
}
