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

node *reverse(node *head)
{

    node *prevptr = NULL;

    while (head != NULL)
    {
        node *nextptr = head->next;
        head->next = prevptr;
        prevptr = head;
        head = nextptr;
    }
    // head = prevptr;

    return prevptr;
}

bool palindrome(node *head)
{
    node *fast = head;
    node *slow = head;

    while (fast->next and fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)
    {
        slow = slow->next;
    }

    node *newhead = reverse(slow);

    while (newhead)
    {
        if (newhead->data != head->data)
        {
            return false;
        }
        else
        {
            newhead = newhead->next;
            head = head->next;
        }
    }
    return true;
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
    head->next->next->next->next = new node(2);
    head->next->next->next->next->next = new node(1);
    // head->next->next->next->next->next->next = new node(5);

    display(head);
    cout << palindrome(head);
}