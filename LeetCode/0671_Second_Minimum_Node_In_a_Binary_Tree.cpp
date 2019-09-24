#include <set>
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
    int findSecondMinimumValue(TreeNode *root)
    {
        dfs(root);
        if (s.size() < 2)
            return -1;
        auto first = s.begin();
        auto second = ++s.begin();
        if (*first == *second)
            return -1;
        else
            return *second;
    }

private:
    set<int> s;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        s.insert(root->val);
        dfs(root->left);
        dfs(root->right);
        return;
    }
};