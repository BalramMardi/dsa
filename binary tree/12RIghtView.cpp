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
        int n = q.size();

        while (n--)
        {
            node *cur = q.front();
            q.pop();

            if (n == 0)
            {
                cout << cur->data << " ";
            }
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
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
