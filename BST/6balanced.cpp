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
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node *balanced(int arr[], int start, int end)
{

    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);

    root->left = balanced(arr, start, mid - 1);
    root->right = balanced(arr, mid + 1, end);
    return root;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    node *root = balanced(arr, 0, 4);
    inorder(root);
}