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

node *insert(node *current, int data)
{
    node *newNode = new node(data);
    current->next = newNode;
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
        current = current->next;
    }
    return;
}

node *findMiddle(node *head)
{
    if (head->next == nullptr || head == nullptr)
    {
        return head;
    }
    node *slow = head;
    node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

    node *middle = findMiddle(head);
    cout << middle->data;

    return 0;
}