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

node *addLinkedLists(node *head1, node *head2)
{
    int carry = 0;
    node *dummyHead = new node(0);
    node *current = dummyHead;

    while (head1 != nullptr || head2 != nullptr || carry == 1)
    {
        int value1 = (head1 != nullptr) ? head1->data : 0;
        int value2 = (head2 != nullptr) ? head2->data : 0;

        int sum = value1 + value2 + carry;
        carry = sum / 10;
        int newValue = sum % 10;

        current->nextNode = new node(newValue);
        current = current->nextNode;

        if (head1 != nullptr)
            head1 = head1->nextNode;
        if (head2 != nullptr)
            head2 = head2->nextNode;
    }

    node *result = reverse(dummyHead->nextNode);
    delete dummyHead;
    return result;
}

int main()
{
    int n;
    cin >> n;
    node *head1;
    node *head2;
    node *current;
    if (n > 0)
    {
        int a;
        cin >> a;
        head1 = new node(a);
        current = head1;
        for (int i = 1; i < n; i++)
        {
            cin >> a;
            current = addToNode(current, a);
        }
    }
    cin >> n;
    if (n > 0)
    {
        int a;
        cin >> a;
        head2 = new node(a);
        current = head2;
        for (int i = 1; i < n; i++)
        {
            cin >> a;
            current = addToNode(current, a);
        }
    }
    head1 = reverse(head1);
    head2 = reverse(head2);
    node *head3 = addLinkedLists(head1, head2);
    display(head3);
    return 0;
}