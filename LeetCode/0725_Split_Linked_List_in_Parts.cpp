#include <vector>
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
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        int count = 0;
        ListNode *ptr = root;
        while (ptr != nullptr)
        {
            ++count;
            ptr = ptr->next;
        }
        vector<ListNode *> res;
        int length = count / k + 1;
        ptr = root;
        ListNode *tmp;
        for (int i = 0; i < count % k; ++i)
        {
            res.push_back(ptr);
            for (int j = 0; j < length - 1; ++j)
                ptr = ptr->next;
            tmp = ptr->next;
            ptr->next = nullptr;
            ptr = tmp;
        }
        --length;
        for (int i = 0; i < k - count % k; ++i)
        {
            res.push_back(ptr);
            for (int j = 0; j < length - 1; ++j)
                ptr = ptr->next;
            if (ptr != nullptr)
            {
                tmp = ptr->next;
                ptr->next = nullptr;
                ptr = tmp;
            }
            else
                ptr = nullptr;
        }
        return res;
    }
};