#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        ListNode *ptr1 = l1, *ptr2 = l2;
        while (ptr1 != nullptr)
        {
            s1.push(ptr1->val);
            ptr1 = ptr1->next;
        }
        while (ptr2 != nullptr)
        {
            s2.push(ptr2->val);
            ptr2 = ptr2->next;
        }
        int carry = 0, sum, x, y;
        l2 = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0)
        {
            if (s1.empty())
                x = 0;
            else
            {
                x = s1.top();
                s1.pop();
            }
            if (s2.empty())
                y = 0;
            else
            {
                y = s2.top();
                s2.pop();
            }
            sum = x + y + carry;
            carry = sum / 10;
            l1 = new ListNode(sum % 10);
            l1->next = l2;
            l2 = l1;
        }
        return l1;
    }
};