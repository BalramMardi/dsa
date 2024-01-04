#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int val;
    Node *next;
};

void atTail(Node **head, int val)
{

    Node *n = new Node();
    n->val = val;
    n->next = *head;

    if (*head == NULL)
    {
        *head = n;
        return;
    }

    Node *temp = *head;
    while (temp)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void append(Node **head_ref, int new_data)
{
    // 1. allocate node
    Node *new_node = new Node();

    Node *temp = *head_ref;

    new_node->val = new_data;

    new_node->next = NULL;

    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // 5. Else traverse till the temp node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // 6. Change the next of temp node
    temp->next = new_node;
    return;
}

void display(Node *node)
{
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
}

int main()
{

    Node *head = NULL;

    append(&head, 11);
    append(&head, 14);
    display(head);
}
