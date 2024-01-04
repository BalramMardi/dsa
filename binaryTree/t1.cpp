#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int data){
        
        Node* temp = new Node;
        temp->data = data;
        temp->left=temp->right=NULL;
        return temp;
}


void printInorder(Node* node)
{
    if (node == NULL)
        return;
 
    
    printInorder(node->left);
 
    
    cout << node->data << " ";
 
    
    printInorder(node->right);
}
int main()
{
 Node *root = newNode(1);
 root -> left = newNode(2);
 root -> right = newNode(3);
 root -> left -> right= newNode(4);
 cout << "\nInorder traversal of binary tree is \n";
 printInorder(root);
 
 
}