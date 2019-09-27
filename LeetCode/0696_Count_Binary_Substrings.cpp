#include <string>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int preLen = 0, curLen = 1, count = 0;
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                ++curLen;
            }
            else
            {
                preLen = curLen;
                curLen = 1;
            }

            if (preLen >= curLen)
            {
                ++count;
            }
        }
        return count;
    }
};