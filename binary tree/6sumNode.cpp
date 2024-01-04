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

int countNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + root->data;
}

int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->right->left = new node(8);

    root->left->left = new node(2);
    root->left->right = new node(4);
    int k = countNodes(root);
    cout << k << endl;
}