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

node *preTree(int pre[], int *preIndex, int key,
              int min, int max, int size)
{
    // Base case
    if (*preIndex >= size)
        return NULL;

    node *root = NULL;

    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key > min && key < max)
    {
        // Allocate memory for root of this
        // subtree and increment *preIndex
        root = new node(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
        {
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such node
            // will be root of left subtree.
            root->left = preTree(pre, preIndex,
                                 pre[*preIndex],
                                 min, key, size);
        }
        if (*preIndex < size)
        {
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such node
            // will be root of right subtree.
            root->right = preTree(pre, preIndex,
                                  pre[*preIndex],
                                  key, max, size);
        }
    }

    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{

    int preorder[] = {10, 2, 1, 13, 11};
    int size = 5;
    int preorderIdx = 0;
    node *root = preTree(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, size);
    inorder(root);
}
