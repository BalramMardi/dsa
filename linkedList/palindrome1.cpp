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

bool palindrome(node *head)
{
    node *temp = head;
    vector<int> vec;

    while (temp != NULL)
    {
        vec.push_back(temp->data);
        temp = temp->next;
    }

    int start = 0;
    int end = vec.size() - 1;

    while (start < end)
    {
        if (vec[start] != vec[end])
        {
            return false;
        }
        start++;
        end--;
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
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(1);
    /*     head->next->next->next->next->next = new node(4);
        head->next->next->next->next->next->next = new node(5); */

    display(head);
    cout << palindrome(head);
}