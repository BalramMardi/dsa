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

bool isValid(node *root, node *min = NULL, node *max = NULL)
{

    if (root == NULL)
    {
        return true;
    }
    if (min != NULL and root->data <= min->data)
    {
        return false;
    }
    if (max != NULL and root->data >= max->data)
    {
        return false;
    }
    bool leftV = isValid(root->left, min, root);
    bool rightV = isValid(root->right, root, max);
    return leftV and rightV;
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

    node *root = new node(50);
    root->left = new node(30);
    root->right = new node(80);
    root->left->left = new node(90);

    root->right->right = new node(20);

    bool isvalid = isValid(root);
    if (isvalid == true)
    {
        cout << "Valid";
    }
    else
        cout << "not Valid";
    /* cout << endl;
    int data;
    cin >> data;
    if (search(root, data) == NULL)
        cout << data << " not found" << endl;
    else
        cout << data << " found" << endl; */
}
// Time Complexity: O(N), where N is the number of nodes of the BST
// Auxiliary Space: O(1)

/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
   */