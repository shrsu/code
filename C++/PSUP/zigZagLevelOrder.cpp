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

vector<vector<int>> zigZagLevelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int numberOfElementsInLevel = q.size();
        vector<int> level(numberOfElementsInLevel); // Ensure proper size for the level vector

        for (int i = 0; i < numberOfElementsInLevel; i++)
        {
            Node *node = q.front();
            q.pop();

            int index = leftToRight ? i : (numberOfElementsInLevel - 1 - i);
            level[index] = node->data;

            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        ans.push_back(level); // Push the level into ans
        leftToRight = !leftToRight;
    }
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

    vector<vector<int>> ans = zigZagLevelOrder(root);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}