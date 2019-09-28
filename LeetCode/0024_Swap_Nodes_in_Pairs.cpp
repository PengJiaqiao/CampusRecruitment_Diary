struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = head;
        ListNode *pos = head->next;
        pre->next = swapPairs(pos->next);
        pos->next = pre;
        return pos;
    }
};