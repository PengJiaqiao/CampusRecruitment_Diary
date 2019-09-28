struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *ptr1 = new ListNode(0);
        ptr1->next = head;
        ListNode *ptr2 = head;
        for (int i = 0; i < n; ++i)
            ptr2 = ptr2->next;
        if(ptr2 == nullptr) return ptr1->next->next;
        while (ptr2 != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = ptr1->next->next;
        return head;
    }
};