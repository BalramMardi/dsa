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

node *duplicate(node *head)
{
    node *dummy = new node(0, head);
    node *prev = dummy;

    while (head != NULL)
    {
        if (head->next != NULL and head->data == head->next->data)
        {
            while (head->next != NULL and head->data == head->next->data)
            {
                head = head->next;
            }
            prev->next = head->next;
        }

        else
        {
            prev = prev->next;
        }

        head = head->next;
    }

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
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(4);
    head->next->next->next->next->next = new node(4);
    head->next->next->next->next->next->next = new node(5);

    node *newhead = duplicate(head);
    display(newhead);
}