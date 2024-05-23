#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

void findPredecessorAndSuccessor(TreeNode *root, int key, TreeNode *&predecessor, TreeNode *&successor)
{
    if (!root)
    {
        return;
    }

    if (root->val == key)
    {
        if (root->left)
        {
            TreeNode *temp = root->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            predecessor = temp;
        }

        if (root->right)
        {
            TreeNode *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            successor = temp;
        }

        return;
    }
    else if (root->val > key)
    {
        successor = root;
        findPredecessorAndSuccessor(root->left, key, predecessor, successor);
    }
    else
    {
        predecessor = root;
        findPredecessorAndSuccessor(root->right, key, predecessor, successor);
    }
}

int main()
{

    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    int keyToSearch = 40;
    TreeNode *predecessor = nullptr;
    TreeNode *successor = nullptr;

    findPredecessorAndSuccessor(root, keyToSearch, predecessor, successor);

    cout << "Predecessor: " << (predecessor ? predecessor->val : -1) << endl;
    cout << "Successor: " << (successor ? successor->val : -1) << endl;

    // Don't forget to free the allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
