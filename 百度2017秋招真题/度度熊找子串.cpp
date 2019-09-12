/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3364&konwledgeId=40 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> v(26, 0);
    int i, idx;
    int start = 0;
    for (i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[start])
        {
            idx = (int)s[start] - 'a';
            v[idx] = max(i - start, v[idx]);
            start = i;
        }
    }
    idx = (int)s[start] - 'a';
    v[idx] = max(i - start, v[idx]);

    int res = 0;
    for (int i = 0; i < 26; ++i)
        res += v[i];
    
    cout << res << endl;

    return 0;
}