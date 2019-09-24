#include <algorithm>
#include <vector>
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
    int rob(TreeNode *root)
    {
        return helper(root)[0];
    }

private:
    vector<int> helper(TreeNode *root)
    {
        vector<int> res = {0, 0};
        if (root == nullptr)
            return res;
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        res[1] = left[0] + right[0];
        res[0] = max(res[1], root->val + left[1] + right[1]);
        return res;
    }
};