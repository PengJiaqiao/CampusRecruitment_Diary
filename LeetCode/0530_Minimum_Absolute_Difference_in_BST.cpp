#include <vector>
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
    int getMinimumDifference(TreeNode *root)
    {
        res.push_back(-2147483647);
        res.push_back(2147483647);
        dfs(root);
        return (int)res[1];
    }

private:
    vector<long long int> res;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        res[1] = min(res[1], root->val - res[0]);
        res[0] = root->val;
        dfs(root->right);
        return;
    }
};