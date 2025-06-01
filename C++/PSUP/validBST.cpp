#include <iostream>
#include <vector>
#include <climits>
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

bool isValidBST(Node *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data <= min || root->data >= max)
    {
        return false;
    }
    return isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
}

int main()
{
    Node *root = nullptr;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        root = insert(root, a);
    }
    if (isValidBST(root))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}