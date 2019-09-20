#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Solution
{
public:
    pair<int, int> findZeroAndOne(string &s)
    {

        int zero = 0, one = 0;
        for (char c : s)
        {
            if (c == '0')
                zero++;
            else
                one++;
        }
        pair<int, int> res = make_pair(zero, one);
        return res;
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs)
        {
            pair<int, int> tmp = findZeroAndOne(str);
            if (tmp.first > m || tmp.second > n)
                continue;
            for (int i = m; i >= tmp.first; --i)
            {
                for (int j = n; j >= tmp.second; --j)
                    dp[i][j] = max(dp[i][j], dp[i - tmp.first][j - tmp.second] + 1);
            }
        }
        return dp[m][n];
    }
};