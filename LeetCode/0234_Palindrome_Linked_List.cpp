struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *ptr1 = head, *ptr2 = head;
        while (ptr2 != nullptr && ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        ptr1 = reverseList(ptr1);
        ptr2 = head;
        while (ptr1 != nullptr)
        {
            if (ptr1->val != ptr2->val)
                return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};