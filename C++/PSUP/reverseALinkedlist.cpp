#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

node *addItem(node *current, int data)
{
    node *newNode = new node(data);
    current->nextNode = newNode;
    return newNode;
}

void display(node *head)
{
    if (head == nullptr)
        return;
    node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->nextNode;
    }
    return;
}

node *reverse(node *head)
{
    if (head == nullptr || head->nextNode == nullptr)
    {
        return head;
    }

    node *previousNode = nullptr;
    node *currentNode = head;
    node *nextNode = nullptr;

    while (currentNode != nullptr)
    {
        nextNode = currentNode->nextNode;
        currentNode->nextNode = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    head = previousNode;
    return head;
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
            current = addItem(current, a);
        }
    }

    head = reverse(head);
    display(head);
    return 0;
}