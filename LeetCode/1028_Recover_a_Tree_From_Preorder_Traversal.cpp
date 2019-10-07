#include <string>
#include <stack>
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
    TreeNode *recoverFromPreorder(string S)
    {
        stack<pair<TreeNode *, int>> stack;
        TreeNode *fakeHead = new TreeNode(0);
        stack.push(make_pair(fakeHead, -1));
        int pre = 0;
        S.push_back('-');
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '-')
                continue;
            int j = i;
            while (S[j] != '-')
                ++j;
            TreeNode *cur = new TreeNode(stoi(S.substr(i, j - i)));
            pair<TreeNode *, int> tmp = make_pair(cur, i - pre);
            pre = j;
            i = j - 1;
            if (tmp.second > stack.top().second)
            {
                stack.top().first->left = cur;
                stack.push(tmp);
            }
            else
            {
                while (stack.top().second >= tmp.second)
                    stack.pop();
                stack.top().first->right = cur;
                stack.push(tmp);
            }
        }

        return fakeHead->left;
    }
};