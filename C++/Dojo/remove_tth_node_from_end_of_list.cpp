#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // Create a dummy node to handle edge cases
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    // Initialize two pointers, first and second, both pointing to dummy node initially
    ListNode *first = dummy;
    ListNode *second = dummy;

    // Move the first pointer ahead by n steps
    for (int i = 0; i < n; ++i)
    {
        if (first == nullptr) // If n exceeds the length of the list
            return head;      // No changes required, return the original list
        first = first->next;
    }

    // Move both pointers together until the first pointer reaches the end
    while (first->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    // At this point, the second pointer is pointing to the node just before the nth node from the end
    // Remove the nth node from the end
    ListNode *temp = second->next;
    second->next = second->next->next;
    delete temp;

    // Store the result after removing the nth node and return it
    ListNode *result = dummy->next;
    delete dummy; // Delete the dummy node
    return result;
}

void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "None" << endl;
}

int main()
{
    // Create a linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode *newHead = removeNthFromEnd(head, n);

    cout << "Original list:" << endl;
    printLinkedList(head);

    cout << "After removing the " << n << "th node from the end:" << endl;
    printLinkedList(newHead);

    // Free memory
    ListNode *temp;
    while (newHead != nullptr)
    {
        temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
