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

// CYCLE-----
node *detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    // if there is no cycle then the pointer will reach to null at some point of time.
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}
node *detectFirstNode(node *&head)
{
    node *meet = detectCycle(head);
    node *start = head;
    while (start != meet)
    {
        start = start->next;
        meet = meet->next;
    }
    return start;
}

// KAPPEND
/* int len(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
} */
node *kappend(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head;

    // int l = len(head);
    // k = k % l;
    int count = 1;
    /* while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    } */

    while (tail->next != NULL)
    {
        if (count == k)
        {
            newTail = tail;
        }
        if (count == k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

// MERGE
node *merge(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummy = new node(-1);
    node *p3 = dummy;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    while (p1 != NULL and p2 != NULL)
    {
        /* code */
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}

node *mergeRecursive(node *head1, node *head2)
{

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    display(head);
    /*    insertAtHead(head, 4);
       display(head);
       cout << search(head, 4) << endl;

       deleteNode(head, 3);
       display(head);

       node *newhead = reveresRecursive(head);
       display(newhead); */

    // node *newhead = kreverse(head, 4);
    // display(newhead);

    node *newhead = kappend(head, 4);
    display(newhead);
    node *head1 = NULL;
    node *head2 = NULL;

    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 8};
    for (int i = 0; i < 4; i++)
    {
        insertAtTail(head1, arr1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        insertAtTail(head2, arr2[i]);
    }
    node *newhead2 = mergeRecursive(head1, head2);
    display(newhead2);
}