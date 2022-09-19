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

void sumRight(Node *root, long long &ans, int pos)
{
    if (root == NULL)
        return;
    // Neu root la not la
    if (root->left == NULL && root->right == NULL)
    {
        if (pos == 1)
            ans += root->val;
    }
    else
    {
        sumRight(root->left, ans, 0);
        sumRight(root->right, ans, 1);
    }
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
        long long ans = 0;
        sumRight(root, ans, -1);
        cout << ans << endl;
    }
}