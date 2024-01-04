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
node *itInsert(node *root, int data)
{
    node *newNode = new node(data);
    node *cur = root;
    node *parent = NULL;

    // until curr is null
    while (cur != NULL)
    {
        parent = cur; // pass the parent to the current node
        // if data is smaller than the current node then go left else go right
        if (data < cur->data)
        {
            cur = cur->left;
        }
        else
            cur = cur->right;
    }

    // if parent is null, deadend reached so return newNode...
    if (parent == NULL)
    {
        return newNode;
    }
    // else if data is less than parent then set left of parent to newNode else right to newNode...
    else if (data < parent->data)
    {
        parent->left = newNode;
    }
    else
        parent->right = newNode;

    // at the end if it reach here then return root
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

node *search(node *root, int target)
{

    if (root == NULL or root->data == target)
    {
        return root;
    }
    if (root->data > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}

int main()
{
    /* node *root = new node(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80); */

    node *root = new node(50);

    itInsert(root, 30);
    itInsert(root, 20);
    itInsert(root, 40);
    itInsert(root, 70);
    itInsert(root, 60);
    itInsert(root, 80);
    inorder(root);
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