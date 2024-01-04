#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    node *next;
    node *prev;
    int data;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {

        head->prev = n;
    }
    head = n;
}

void insertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

// DELETE---------------

void deleteAtHead(node *&head)
{
    node *todel = head;
    head = head->next;
    head->prev = NULL;
    delete todel;
}

void deleteNode(node *&head, int pos)
{
    /* node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *del = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;
    delete del; */

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL and count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

// DISPLAY---------------
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// APPEND-----

int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head, 5);
    display(head);
    deleteNode(head, 3);
    display(head);
}