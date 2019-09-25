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
    TreeNode *convertBST(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        int sum = 0;
        stack<TreeNode *> s;
        TreeNode *node = root;
        while (node || !s.empty())
        {
            while (node)
            {
                s.push(node);
                node = node->right;
            }
            node = s.top();
            s.pop();
            int val = node->val;
            node->val += sum;
            sum += val;
            node = node->left;
        }
        return root;
    }
};