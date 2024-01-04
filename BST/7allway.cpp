#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<node *> generateBSTs(int start, int end)
{
    vector<node *> result;

    if (start > end)
    {
        result.push_back(nullptr);
        return result;
    }

    for (int i = start; i <= end; i++)
    {
        vector<node *> leftSubtrees = generateBSTs(start, i - 1);
        vector<node *> rightSubtrees = generateBSTs(i + 1, end);

        for (node *left : leftSubtrees)
        {
            for (node *right : rightSubtrees)
            {
                node *root = new node(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
}

void printInorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    int n = 3; // Number of nodes (Example: n = 3)
    vector<node *> allBSTs = generateBSTs(1, n);

    for (int i = 0; i < allBSTs.size(); i++)
    {
        cout << "BST " << i + 1 << ": ";
        printInorder(allBSTs[i]);
        cout << endl;
    }

    return 0;
}