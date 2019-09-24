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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return depth(root);
    }

private:
    int depth(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        if (root->left == nullptr)
            return 1 + depth(root->right);
        if (root->right == nullptr)
            return 1 + depth(root->left);
        return 1 + min(depth(root->left), depth(root->right));
    }
};