#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *oddeven(ListNode *head)
{
    // Initialize pointers
    ListNode *odd_head = new ListNode(0);
    ListNode *odd = odd_head;
    ListNode *even_head = new ListNode(0);
    ListNode *even = even_head;
    ListNode *curr = head;
    int counter = 1;

    cout << "odd started--->" << odd->val << endl;
    cout << "even started--->" << even->val << endl;
    cout << "curr--->" << curr->val << endl;
    // Traverse the original linked list
    while (curr)
    {
        if (counter % 2 == 1)
        {
            // Odd-positioned node
            odd->next = curr;
            cout << "odd before-> " << odd->val << endl;

            odd = odd->next;
            cout << "odd-> " << odd->val << endl;
        }
        else
        {
            // Even-positioned node
            even->next = curr;
            even = even->next;
            cout << "even-> " << even->val << endl;
        }

        // Move to the next node
        curr = curr->next;
        cout << "curr---->" << curr->val << endl;

        cout << counter << endl;
        cout << "----------COUNTER-----------" << endl;
        counter++;
    }

    // Merge the odd-positioned linked list and the even-positioned linked list
    odd->next = even_head->next;
    even->next = NULL;

    // Return the rearranged linked list
    return odd_head->next;
}

int main()
{
    // Create the linked list 1->2->3->4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Rearrange the linked list
    ListNode *new_head = oddeven(head);

    // Print the rearranged linked list
    while (new_head)
    {
        cout << new_head->val << "->";
        new_head = new_head->next;
    }

    return 0;
}
// This code is written by Abhay_Mishra
