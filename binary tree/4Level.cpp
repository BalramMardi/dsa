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

void level(node *root)
{

    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->left != NULL)
        {
            q.push(cur->left);
        }
        if (cur->right != NULL)
        {
            q.push(cur->right);
        }
    }
}

int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);

    level(root);
}

/*
Time Complexity: O(N) where N is the number of nodes in the binary tree.
Auxiliary Space: O(N) where N is the number of nodes in the binary tree.

*/

/* void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int height(node* node)
{
    if (node == NULL)
        return 0;
    else {

        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // Use the larger one
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

// Print nodes at a current level
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
} */