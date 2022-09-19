#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
// Ham tim chieu cao cua cay

bool check(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if ((root->left && !root->right) || (!root->left && root->right))
        return false;
    return check(root->left) && check(root->right);
}

void makeRoot(Node *root, int u, int v, char c)
{
    if (c == 'L')
        root->left = new Node(v);
    else
        root->right = new Node(v);
}

void insertNode(Node *root, int u, int v, char c)
{
    if (root == NULL)
        return;
    if (root->val == u)
    {
        makeRoot(root, u, v, c);
    }
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *root = NULL;
        while (n--)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == NULL)
            {
                root = new Node(u);
                makeRoot(root, u, v, c);
            }
            else
                insertNode(root, u, v, c);
        }
        if (check(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}