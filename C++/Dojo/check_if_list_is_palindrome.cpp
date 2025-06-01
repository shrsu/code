#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *nextNode;

    node(int data)
    {
        this->data = data;
        this->nextNode = nullptr;
    }
};

node *addToNode(node *current, int data)
{
    node *newNode = new node(data);
    current->nextNode = newNode;
    return newNode;
}

bool isPalindrome(node *head)
{
    if (head == nullptr || head->nextNode == nullptr)
        return true;

    stack<int> values;
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->nextNode != nullptr)
    {
        values.push(slow->data);
        slow = slow->nextNode;
        fast = fast->nextNode->nextNode;
    }

    if (fast != nullptr)
    {
        slow = slow->nextNode;
    }

    while (slow != nullptr)
    {
        int top = values.top();
        values.pop();

        if (slow->data != top)
            return false;

        slow = slow->nextNode;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    node *head;
    node *current;

    if (n > 0)
    {
        int a;
        cin >> a;
        head = new node(a);
        current = head;
        for (int i = 1; i < n; i++)
        {
            cin >> a;
            current = addToNode(current, a);
        }
    }

    if (isPalindrome(head))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}