#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> cnt(58, 0);
        for (int i = 0; i < s.size(); ++i)
            ++cnt[s[i] - 'A'];
        int res = s.size();
        for (int i = 0; i < 58; ++i)
        {
            if (cnt[i] % 2 == 1)
                --res;
        }
        return res < s.size() ? ++res : res;
    }
};