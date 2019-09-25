#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
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
    vector<int> findMode(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *node;
        unordered_map<int, int> M;
        while (!s.empty())
        {
            node = s.top();
            s.pop();
            if (M.find(node->val) == M.end())
                M[node->val] = 1;
            else
                ++M[node->val];
            if (node->right != nullptr)
                s.push(node->right);
            if (node->left != nullptr)
                s.push(node->left);
        }

        vector<pair<int, int>> tmp;
        vector<int> res;
        for (auto m : M)
            tmp.push_back(make_pair(m.first, m.second));
        sort(tmp.begin(), tmp.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
        int cnt = tmp[0].second;
        for (int i = 0; i < tmp.size(); ++i)
        {
            if (tmp[i].second == cnt)
                res.push_back(tmp[i].first);
            else
                break;
        }
        return res;
    }
};