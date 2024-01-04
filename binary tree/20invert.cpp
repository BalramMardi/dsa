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

node *invert(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    invert(root->left);
    invert(root->right);
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
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
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(7);
    root->right->left = new node(6);
    root->right->left->left = new node(8);
    root->right->left->left->right = new node(9);
    invert(root);

    preorder(root);
}
