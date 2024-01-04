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
/* void convertToDLL(node *root, node *&prev, node *&head)
{
    if (root == NULL)
    {
        return;
    }
    convertToDLL(root->left, prev, head);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convertToDLL(root->right, prev, head);
} */

void flatten(node *root, node *&prev)
{
    if (!root)
        return;
    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}
void inorder(node *root)
{
    // base condition
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    root->right->left->left = new node(8);
    root->right->left->left->right = new node(9);
    node *prev = NULL;

    flatten(root, prev);
    inorder(root);
}

// Time complexity: O(n), for visiting all the nodes in the tree once.
// Space complexity: O(n), we are making a recursion call for every node in the tree.