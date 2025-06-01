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

node *create(node *current, int data)
{
    node *newNode = new node(data);
    current->nextNode = newNode;
    return newNode;
}

void insert(node *&head, int index, int data)
{
    node *newNode = new node(data);
    node *current = head;

    if (index == 0)
    {
        newNode->nextNode = head;
        head = newNode;
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        if (current->nextNode == nullptr && i < index - 2)
        {

            return;
        }
        current = current->nextNode;
    }

    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

void del(node *&head, int index)
{
    node *current = head;
    if (index == 0)
    {
        head = head->nextNode;
        delete head;
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        if (current->nextNode == nullptr && i < index - 2)
        {
            return;
        }
        current = current->nextNode;
    }
    node *nodeToDelete = current->nextNode;
    current->nextNode = current->nextNode->nextNode;
    delete nodeToDelete;
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
    node *head = nullptr;
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
            current = create(current, a);
        }
    }
    int ele, index1;
    cin >> ele >> index1;
    int index2;
    cin >> index2;
    insert(head, index1, ele);
    del(head, index2);
    display(head);
}