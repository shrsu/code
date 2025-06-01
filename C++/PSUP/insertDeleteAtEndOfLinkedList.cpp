#include <iostream>
#include <cstdlib>

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

node *insert(node *current, int a)
{
    node *newNode = new node(a);
    current->nextNode = newNode;
    return newNode;
}

void deleteAtEnd(node *&head)
{
    if (head == nullptr)
    {
        return; // No nodes in the linked list
    }

    // Only 1 node exists
    if (head->nextNode == nullptr)
    {
        int data = head->data;
        delete head;
        head = nullptr;
        return;
    }

    node *current = head;
    while (current->nextNode->nextNode != nullptr)
    {
        current = current->nextNode;
    }

    delete current->nextNode;
    current->nextNode = nullptr;
}

void display(node *head)
{
    node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->nextNode;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    node *head = nullptr, *current = nullptr;

    if (n > 0)
    {
        int a;
        cin >> a;
        head = new node(a);
        current = head;
        for (int i = 1; i < n; i++)
        {
            cin >> a;
            current = insert(current, a);
        }
    }

    deleteAtEnd(head);
    display(head);

    return 0;
}
