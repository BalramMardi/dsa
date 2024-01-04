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

void sumReplacement(node *root)
{
    if (root == NULL)
        return;

    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left)
    {
        root->data += root->left->data;
    }
    if (root->right)
    {
        root->data += root->right->data;
    }
}

void preorder(struct node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->right->left = new node(8);

    root->left->left = new node(2);
    root->left->right = new node(4);
    preorder(root);
    cout << endl;
    sumReplacement(root);
    cout << endl;

    preorder(root);
}

// time:O(n);
