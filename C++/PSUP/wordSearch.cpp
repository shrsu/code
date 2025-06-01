#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool search(vector<vector<char>> &board, int i, int j, int n, int m, string &word, int k)
{
    if (k == word.size())
    {
        return true;
    }

    if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
    {
        return false;
    }

    board[i][j] = '#';

    bool op1 = search(board, i + 1, j, n, m, word, k + 1);
    bool op2 = search(board, i, j + 1, n, m, word, k + 1);
    bool op3 = search(board, i - 1, j, n, m, word, k + 1);
    bool op4 = search(board, i, j - 1, n, m, word, k + 1);

    board[i][j] = word[k];

    return op1 || op2 || op3 || op4;
}

bool present(vector<vector<char>> &board, string word, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (search(board, i, j, n, n, word, 0))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // Enter your code below
    int n;
    cin >> n;
    string s;
    vector<vector<char>> board(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    cin >> s;

    if (present(board, s, n, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}