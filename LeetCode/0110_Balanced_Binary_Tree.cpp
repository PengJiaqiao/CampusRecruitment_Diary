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
    bool isBalanced(TreeNode *root)
    {
        maxDepth(root);
        return res;
    }

private:
    bool res = true;
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if (abs(l - r) > 1)
            res = false;
        return 1 + max(l, r);
    }
};