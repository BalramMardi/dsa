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

node *findLCA(node *root, int n1, int n2)
{
    // Base case
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    node *left_lca = findLCA(root->left, n1, n2);

    node *right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

int findDist(node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dist;
    }
    int left = findDist(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return findDist(root->right, k, dist + 1);
}

int distBtwNodes(node *root, int n1, int n2)
{
    node *lca = findLCA(root, n1, n2);
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return d1 + d2;
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
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << a << "," << b << " --> " << distBtwNodes(root, a, b);
        cout << endl;
    }
}

// Time Complexity: O(n), As the method does a single tree traversal. Here n is the number of elements in the tree.
// Auxiliary Space: O(h), Here h is the height of the tree and the extra space is used in recursion call stack.