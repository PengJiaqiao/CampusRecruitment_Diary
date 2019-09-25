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
    vector<int> v;
    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;
        if (find(v.begin(), v.end(), k - root->val) != v.end())
            return true;
        v.push_back(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};