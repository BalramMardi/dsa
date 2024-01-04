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
};

// INSERT----
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {

        temp = temp->next;
    }
    temp->next = n;
}

// SEARCH----
bool search(node *head, int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// DELETE----
void deleteAtHead(node *&head)
{
    node *todel = head;
    head = head->next;
}

void deleteNode(node *head, int val)
{

    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

// REVERSE----
node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *current = head;
    node *nextptr;

    while (current != NULL)
    {
        nextptr = current->next;
        current->next = prevptr;
        prevptr = current;
        current = nextptr;
    }
    // head = prevptr;

    return prevptr;
}

node *reveresRecursive(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reveresRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node *kreverse(node *&head, int k)
{

    node *prev = NULL;
    node *curr = head;
    node *next;

    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
        head->next = kreverse(next, k);

    return prev;
}

// DISPLAY-----
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

void evenodd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;
    while (odd->next != NULL and even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if (odd->next == NULL)
    {
        even->next = NULL;
    }
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 6);

    display(head);
    evenodd(head);
    display(head);
}