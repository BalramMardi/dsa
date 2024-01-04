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

node *insert(node *root, int data)
{

    if (root == NULL)
    {
        return new node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int maxx(node *root)
{
    if (root->right != NULL)
    {
        return maxx(root->right);
    }
    else
    {
        return root->data;
    }
}

node *deleteBst(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key > root->data)
    {
        root->right = deleteBst(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = deleteBst(root->left, key);
    }
    else
    {
        if (root->left != NULL and root->right != NULL)
        {
            int lmax = maxx(root->left);
            root->data = lmax;
            root->left = deleteBst(root->left, lmax);
            return root;
        }
        else if (root->left != NULL)
        {
            return root->left;
        }
        else if (root->right != NULL)
        {
            return root->right;
        }
        else
        {
            return NULL;
        }
    }
    return root;
}

int main()
{
    node *root = new node(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Original BST: ");
    inorder(root);
    cout << endl;
    printf("New BST: ");

    printf("After removing the left leaf node: \n");

    root = deleteBst(root, 20);

    inorder(root);

    printf("\nAfter removing the node having one child: \n");

    root = deleteBst(root, 30);

    inorder(root);

    printf("\nAfter removing the node having two child: \n");

    root = deleteBst(root, 70);

    inorder(root);
}

/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
   */

/// Time complexity=O(log N)
// Space complexity=O(log N)
