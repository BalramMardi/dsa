#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

void order(Node* root){
    if(root ==NULL)
    return;


    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* node =q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);

        }
        else if(!q.empty())
            q.push(NULL);
        
    }
    


}

    

int main()
{
 Node* root = new Node(1);
 root->left=new Node(7);
 root->right=new Node(8);
 root->left->left=new Node(4);
 root->left->right=new Node(5);
 order(root);

 
 
}