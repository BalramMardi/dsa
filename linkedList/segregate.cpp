#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void segregateEvenOdd(struct Node **head_ref)
{

    Node *evenStart = NULL;

    Node *evenEnd = NULL;

    Node *oddStart = NULL;

    Node *oddEnd = NULL;

    Node *currNode = *head_ref;

    while (currNode != NULL)
    {
        int val = currNode->data;

        if (val % 2 == 0)
        {
            if (evenStart == NULL)
            {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else
            {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }

        else
        {
            if (oddStart == NULL)
            {
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else
            {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }

        currNode = currNode->next;
    }

    if (oddStart == NULL || evenStart == NULL)
        return;

    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    *head_ref = evenStart;
}

void push(Node **head_ref, int new_data)
{

    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    *head_ref = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{

    Node *head = NULL;

    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 4);
    push(&head, 1);
    push(&head, 0);
    push(&head, 20);
    push(&head, 31);

    cout << "Original Linked list" << endl;
    printList(head);

    segregateEvenOdd(&head);

    cout << endl
         << "Modified Linked list " << endl;
    printList(head);

    return 0;
}
