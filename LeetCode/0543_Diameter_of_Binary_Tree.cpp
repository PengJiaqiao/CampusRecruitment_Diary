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
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return res;
    }

private:
    int res = 0;
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
};