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
    int sumNumbers(TreeNode *root)
    {
        solution(root, 0);
        return res;
    }

private:
    int res = 0;
    void solution(TreeNode *root, int pre)
    {
        if (root == nullptr)
            return;
        pre = pre * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            res += pre;
            return;
        }
        else
        {
            solution(root->left, pre);
            solution(root->right, pre);
            return;
        }
    }
};