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

int diameter(node *root, int *height)
{
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;

    if (root == NULL)
    {
        height = 0;
        return 0;
    }

    ldiameter = diameter(root->left, &lh);
    rdiameter = diameter(root->right, &rh);

    *height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ldiameter, rdiameter));
}
int main()
{
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->right->left = new node(8);

    root->left->left = new node(2);
    root->left->right = new node(4);
    int height = 0;
    int k = diameter(root, &height);
    cout << k << endl;
}

// time:O(N)
// spac :O(N)

//---------------------------------------------

/* int diameter(struct node* tree)
{
    // base case where tree is empty
    if (tree == NULL)
        return 0;

    // get the height of left and right sub-trees
    int lheight = height(tree->left);
    int rheight = height(tree->right);

    // get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree +
    // 1
    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}


Time Complexity: O(N²)
Auxiliary Space: O(N) for call stack

*/

//------------------------------------------
// Morris Traversal is also there