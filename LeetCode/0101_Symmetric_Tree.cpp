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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == nullptr && r2 == nullptr)
            return true;
        if (r1 == nullptr || r2 == nullptr)
            return false;
        if (r1->val != r2->val)
            return false;
        return isSymmetric(r1->right, r2->left) && isSymmetric(r1->left, r2->right);
    }
};