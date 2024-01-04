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

void printKdistance(node *root, int k)
{

    if (root == NULL or k < 0)
        return;

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    printKdistance(root->left, k - 1);
    printKdistance(root->right, k - 1);
}

int upPrint(node *root, node *target, int k)
{
    if (root == NULL)
        return -1;

    if (root == target)
    {
        printKdistance(root, k);
        return 0;
    }
    int dl = upPrint(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
            cout << root->data << endl;

        else
            printKdistance(root->right, k - dl - 2);

        return 1 + dl;
    }

    int dr = upPrint(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << endl;
        else
            printKdistance(root->left, k - dr - 2);
        return 1 + dr;
    }

    return -1;
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
    node *target = root->right;
    upPrint(root, target, 2);
}
