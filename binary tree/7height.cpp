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

int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {

        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // Use the larger one

        return max(lheight, rheight) + 1;
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
    int k = height(root);
    cout << k << endl;
}

/*
Time Complexity: O(N) (Please see the post on Tree Traversal for details)
Auxiliary Space: O(N) due to recursive stack.

*/
