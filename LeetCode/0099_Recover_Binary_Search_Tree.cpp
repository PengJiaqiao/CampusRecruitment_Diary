#include <stack>
#include <limits.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        stack<TreeNode *> s;
        TreeNode *node = root, *pre, *cur;
        bool flag = true;
        int preVal = INT_MIN;
        while (node != nullptr || !s.empty())
        {
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            if (node->val < preVal)
            {
                if (flag)
                {
                    flag = false;
                    cur = node;
                }
                else
                {
                    int tmp = pre->val;
                    pre->val = node->val;
                    node->val = tmp;
                    return;
                }
            }
            if (flag)
                pre = node;
            preVal = node->val;
            node = node->right;
        }
        int tmp = pre->val;
        pre->val = cur->val;
        cur->val = tmp;
        return;
    }
};