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

Node *makeTree(int pre[], int *idx, int l, int r, int n)
{
    if (*idx >= n || l > r)
        return NULL;
    Node *root = new Node(pre[*idx]);
    ++(*idx);
    if (l == r)
        return root;
    int res;
    for (int i = l; i <= r; i++)
    {
        if (pre[i] > root->val)
        {
            res = i;
            break;
        }
    }
    root->left = makeTree(pre, idx, *idx, res - 1, n);
    root->right = makeTree(pre, idx, res, r, n);
    return root;
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int pre[n];
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        int idx = 0;
        Node *root = makeTree(pre, &idx, 0, n - 1, n);
        postOrder(root);
        cout << endl;
    }
}