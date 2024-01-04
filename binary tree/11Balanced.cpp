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

int height(node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

// Time Complexity: O(n^2) in case of full binary tree.
// Auxiliary Space: O(n)

bool balanced(node *root)
{
    if (root == NULL)
        return true;

    if (balanced(root->left) == false)
    {
        return false;
    }
    if (balanced(root->right) == false)
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) < 2)
    {
        return true;
    }

    else
        return false;
}

//----------------------------------------------------------------------------------------//

// Time Complexity: O(n)

bool isbalanced(node *root, int *height)
{
    if (root == NULL)
        return true;
    int lh = 0, rh = 0;

    if (isbalanced(root->left, &lh) == false)
        return false;

    if (isbalanced(root->right, &rh) == false)
        return false;

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->right->left = new node(8);

    root->left->left = new node(2);
    root->left->right = new node(4);
    cout << balanced(root) << endl;
    int height = 0;
    cout << isbalanced(root, &height);
}

// time:O(n);
