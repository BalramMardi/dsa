#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool order(node *root, vector<int> &path, int k)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == k)
    {
        return true;
    }

    if (root->left)
    {
        if (order(root->left, path, k))
        {
            return true;
        }
    }
    if (root->right)
    {
        if (order(root->right, path, k))
        {
            return true;
        }
    }

    path.pop_back();
    return false;
}

int lca(node *root, int n1, int n2)
{

    vector<int> path1, path2;

    if (!order(root, path1, n1))
    {
        return -1;
    }
    if (!order(root, path2, n2))
    {
        return -1;
    }

    int i;
    for (i = 0; i < path1.size() and i < path2.size(); i++)
    {
        if (path1[i] != path2[i])
        {
            break;
        }
    }
    return path1[i - 1];
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(7);
    root->right->right->left = new node(6);
    cout << "LCA(4, 7) = " << lca(root, 4, 7);
}
