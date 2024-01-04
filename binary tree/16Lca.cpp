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

    if ((root->left and (order(root->left, path, k))) or (root->right and (order(root->right, path, k))))
    {

        return true;
    }

    path.pop_back();
    return false;
}

int lca(node *root, int n1, int n2)
{

    vector<int> path1, path2;

    if (!order(root, path1, n1) or !order(root, path2, n2))
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
    root->right->left = new node(6);
    cout << "LCA(6, 3) = " << lca(root, 6, 3);
}

// Time Complexity: O(N). The tree is traversed twice, and then path arrays are compared.
// Auxiliary Space: O(N). Extra Space for path1 and path2.