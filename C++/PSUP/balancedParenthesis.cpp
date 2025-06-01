#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> stac;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '{':
        case '(':
        case '[':
            stac.push(s[i]);
            break;
        case '}':
        case ')':
        case ']':
            if (stac.empty())
                return false;
            char top = stac.top();
            stac.pop();
            if ((s[i] == '}' && top != '{') ||
                (s[i] == ')' && top != '(') ||
                (s[i] == ']' && top != '['))
            {
                return false;
            }

            break;
        }
    }
    return stac.empty();
}

int main()
{
    string s;
    cin >> s;
    if (isValid(s))
        cout << "true";
    else
        cout << "false";
}