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

node *fromend(node *head, int n)
{
    node *dummy = new node(0);
    dummy->next = head;
    node *curr = dummy, *nth = dummy;

    for (int i = 1; i <= n + 1; i++)
    {
        curr = curr->next;
    }

    while (curr != NULL)
    {
        curr = curr->next;
        nth = nth->next;
    }

    nth->next = nth->next->next;

    return dummy->next;
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

    int n;
    cin >> n;
    node *newhead = fromend(head, n);
    display(newhead);
}