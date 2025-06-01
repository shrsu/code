#include <iostream>
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

void createLoop(node *head, node *tail, int position)
{
    if (head == nullptr || position == 0)
    {
        return;
    }
    node *current = head;
    for (int i = 0; i < position - 1; i++)
    {
        current = current->nextNode;
    }
    tail->nextNode = current;
}

bool detectLoop(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != nullptr && fast->nextNode != nullptr)
    {
        slow = slow->nextNode;
        fast = fast->nextNode->nextNode;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    node *head;
    node *current;
    node *tail;
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
        tail = current;
    }
    int position;
    cin >> position;
    createLoop(head, tail, position);
    if (detectLoop(head))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}