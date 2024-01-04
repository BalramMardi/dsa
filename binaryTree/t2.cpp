#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data =val;
        right =NULL;
        left = NULL;
    }
};

void preorder(Node *root)
{
    if (root==NULL)
    {
        
        return;
    }
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root==NULL)
    {
        /* code */
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}
void postorder(Node *root)
{
    if (root==NULL)
    {
        /* code */
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node *root = new Node(1);
    root->left=new Node(2);
    root->right =new Node(3);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
}
