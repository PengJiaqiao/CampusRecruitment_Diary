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
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;
        return pathSumStartWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int pathSumStartWithRoot(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;
        int res = 0;
        if (root->val == sum)
            res++;
        sum -= root->val;
        res += pathSumStartWithRoot(root->left, sum) +
               pathSumStartWithRoot(root->right, sum);
        return res;
    }
};