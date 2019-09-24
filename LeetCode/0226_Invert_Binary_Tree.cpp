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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *l = invertTree(root->left);
        TreeNode *r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};