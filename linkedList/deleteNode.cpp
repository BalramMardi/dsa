#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
    node(int val, node *head)
    {
        data = val;
        next = head;
    }
};

void delNode(node *node)
{
    cout << node->data << endl;
    node->data = node->next->data;
    node->next = node->next->next;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        /* cout << temp->data << " (" << temp->next << ") "
             << "->"; */
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);

    display(head);
    cout << endl;
    delNode(head->next->next->next);
    display(head);
}