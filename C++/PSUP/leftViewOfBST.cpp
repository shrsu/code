#include <iostream>
#include <vector>
#include <queue>

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
    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void recursion(Node *root, int level, vector<int> &ans)
{
    if (root == nullptr)
    {
        return ;
    }
    if (level == ans.size())
        ans.push_back(root->data);
    recursion(root->left, level + 1, ans);
    recursion(root->right, level + 1, ans);
    return;
}

vector<int> findLeftView(Node *root)
{
    vector<int> ans;
    recursion(root, 0, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    vector<int> ans = findLeftView(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}