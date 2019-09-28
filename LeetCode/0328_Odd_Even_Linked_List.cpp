struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if(head == nullptr)return head;
        ListNode *evenhead = head->next;
        ListNode *ptr1 = head, *ptr2 = head->next;
        while (ptr2 != nullptr && ptr2->next != nullptr)
        {
            ptr1->next = ptr2->next;
            ptr1 = ptr1->next;
            ptr2->next = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = evenhead;
        return head;
    }
};