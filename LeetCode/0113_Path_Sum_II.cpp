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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return {};
        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == root->val)
                return {{root->val}};
            else
                return {};
        }
        vector<vector<int>> res;
        sum -= root->val;
        vector<vector<int>> left = pathSum(root->left, sum);
        vector<vector<int>> right = pathSum(root->right, sum);
        for (vector<int> l : left)
        {
            vector<int> tmp = {root->val};
            tmp.insert(tmp.end(), l.begin(), l.end());
            res.push_back(tmp);
        }
        for (vector<int> r : right)
        {
            vector<int> tmp = {root->val};
            tmp.insert(tmp.end(), r.begin(), r.end());
            res.push_back(tmp);
        }
        return res;
    }
};