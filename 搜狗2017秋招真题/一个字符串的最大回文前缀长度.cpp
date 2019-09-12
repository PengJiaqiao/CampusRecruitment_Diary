/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3336&konwledgeId=156 */

#include <iostream>
#include <string>
using namespace std;

bool isPalindromic(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }

    return true;
}

int main()
{
    string s;
    cin >> s;

    int maxl = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (isPalindromic(s, 0, i))
        {
            maxl = i + 1;
            break;
        }
    }

    cout << maxl << endl;

    return 0;
}