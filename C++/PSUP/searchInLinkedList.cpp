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

bool isPresent(node *head, int item)
{
    if (head == nullptr)
        return false;
    node *current = head;
    while (current != nullptr)
    {
        if (current->data == item)
            return true;
        current = current->nextNode;
    }
    return false;
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

    int target;
    cin >> target;
    if (isPresent(head, target))
        cout << "true";
    else
        cout << "false";
    return 0;
}