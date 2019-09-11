/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3339&konwledgeId=158 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    sort(d.begin(), d.end());

    int res = 0;
    int pre = 1;
    for (int i = 1; i < n; ++i)
    {
        if (pre)
        {
            int diff = d[i] - d[i - 1];
            if (diff > 20)
            {
                res += 3 - pre;
                pre = 1;
            }
            else
            {
                if (diff > 10)
                {
                    res++;
                    pre++;
                }
                pre = (pre + 1) % 3;
            }
        }
        else
            pre++;
    }

    res += pre > 0 ? 3 - pre : 0;
    cout << res << endl;

    return 0;
}
