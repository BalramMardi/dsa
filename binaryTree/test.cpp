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
Node *newNode2(int data){
        
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
 cout << "\nInorder traversal of first binary tree is \n";
 printInorder(root);
 Node *root2 = newNode2(5);
 root2 -> left = newNode2(6);
 root2 -> right = newNode2(7);
 root2 -> left -> right= newNode2(8);
 cout << "\nInorder traversal of second binary tree is \n";
 
printInorder(root2);
 
 
}