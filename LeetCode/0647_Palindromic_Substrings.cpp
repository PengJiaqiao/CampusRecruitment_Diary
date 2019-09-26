#include <string>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            extendSubstrings(s, i, i);
            extendSubstrings(s, i, i + 1);
        }
        return res;
    }

private:
    int res = 0;
    void extendSubstrings(string &s, int start, int end)
    {
        while (start >= 0 && end < s.length() && s[start] == s[end])
        {
            --start;
            ++end;
            ++res;
        }
    }
};