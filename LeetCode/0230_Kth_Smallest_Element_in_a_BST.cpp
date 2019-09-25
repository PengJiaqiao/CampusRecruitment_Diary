#include <stack>
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
    int kthSmallest(TreeNode *root, int k)
    {
        int cnt = 0;
        stack<TreeNode *> s;
        TreeNode *node = new TreeNode(0);
        node->right = root;
        while (cnt++ < k)
        {
            node = node->right;
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
        }
        return node->val;
    }
};