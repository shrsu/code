#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insert(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *removeEvenPositions(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *oddHead = head;
    ListNode *evenHead = head->next;
    ListNode *evenPtr = evenHead;

    while (evenHead != NULL && evenHead->next != NULL)
    {
        oddHead->next = evenHead->next;
        oddHead = oddHead->next;

        evenHead->next = oddHead->next;
        evenHead = evenHead->next;
    }

    ListNode *prev = NULL;
    ListNode *curr = evenPtr;
    ListNode *nextNode;

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    evenPtr = prev;

    oddHead->next = evenPtr;

    return head;
}

int main()
{
    ListNode *head = NULL;

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        insert(head, arr[i]);
    }
    cout << "Original List: ";
    printList(head);

    head = removeEvenPositions(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
