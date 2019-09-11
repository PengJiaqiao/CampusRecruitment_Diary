/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3342&konwledgeId=158 */

#include <iostream>
#include <string>
using namespace std;

bool match(string &s, int stride)
{
    for (int i = 1; i < s.size() / stride; ++i)
    {
        int idx = i * stride;
        for (int j = 0; j < stride; ++j)
        {
            if (s[idx] != s[idx - stride])
            {
                return false;
            }
            idx++;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    int res = 1;
    for (int i = 1; i <= s.size() / 2; ++i)
    {
        if (s.size() % i == 0)
        {
            if (match(s, i))
            {
                res = s.size() / i;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}