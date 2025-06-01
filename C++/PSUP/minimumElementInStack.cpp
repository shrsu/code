#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> originalStack;
    stack<int> minimumStack;

    for (int i = 0; i < n; i++)
    {
        int action;
        cin >> action;

        if (action == 1)
        {
            // Push operation
            int element;
            cin >> element;
            originalStack.push(element);

            if (minimumStack.empty() || element <= minimumStack.top())
            {
                minimumStack.push(element);
            }
        }
        else if (action == 2)
        {
            if (!originalStack.empty())
            {
                if (originalStack.top() == minimumStack.top())
                {
                    minimumStack.pop();
                }
                cout << originalStack.top() << " ";
                originalStack.pop();
            }
            else
            {
                cout << -1 << " ";
            }
        }
        else if (action == 3)
        {
            if (!minimumStack.empty())
            {
                cout << minimumStack.top() << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
    }

    return 0;
}
