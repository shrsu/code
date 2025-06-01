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

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    Node *root = nullptr;
    if (n > 0)
    {
        cin >> arr[0];
        root = insert(root, arr[0]);
        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
            insert(root, arr[i]);
        }
        inOrderPrint(root);
    }

    return 0;
}