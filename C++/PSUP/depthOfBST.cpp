#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *insert(Node *head, int data)
{
    if (head == nullptr)
    {
        return new Node(data);
    }
    if (data < head->data)
    {
        head->left = insert(head->left, data);
    }
    else
    {
        head->right = insert(head->right, data);
    }
    return head;
}

int checkDepth(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int rtdepth = 1 + checkDepth(root->right);
    int lftdepth = 1 + checkDepth(root->left);
    return rtdepth > lftdepth ? rtdepth : lftdepth;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    Node *head = nullptr;
    int depth = 0;
    if (n > 0)
    {
        cin >> arr[0];
        head = insert(head, arr[0]);
        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
            insert(head, arr[i]);
        }
        depth = checkDepth(head);
    }
    cout << depth;
    return 0;
}