#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

node *insert(node *head, int data)
{
    node *newNode = new node(data);
    newNode->next = head;
    return newNode;
}

node *del(node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    node *newHead = head->next;
    delete head;
    return newHead;
}

int main()
{
    int n;
    cin >> n;
    node *head = nullptr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        head = insert(head, a);
    }

    head = del(head);

    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}