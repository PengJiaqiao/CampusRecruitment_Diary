/* https://leetcode.com/problems/linked-list-cycle/ */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *ptr1 = head, *ptr2 = head;
        while (ptr1 != nullptr && ptr2 != nullptr && ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = (ptr2->next)->next;

            if (ptr1 == ptr2)
                return true;
        }
        return false;
    }
};