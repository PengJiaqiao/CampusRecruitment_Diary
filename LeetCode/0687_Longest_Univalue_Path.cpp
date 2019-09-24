#include <algorithm>
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
    int longestUnivaluePath(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        helper(root, root->val);
        return res;
    }

private:
    int res = 0;
    int helper(TreeNode *root, int val)
    {
        if (root == nullptr)
            return 0;
        if (root->val != val)
        {
            helper(root, root->val);
            return 0;
        }
        int l = helper(root->left, val);
        int r = helper(root->right, val);
        res = max(res, 1 + r + l);
        return 1 + max(r, l);
    }
};