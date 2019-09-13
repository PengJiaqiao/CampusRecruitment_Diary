/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3344&konwledgeId=40 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int k;
    int l, n;
    cin >> k;

    while (k--)
    {
        cin >> l >> n;

        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            cin >> pos[i];

        int Min = 0, Max = 0;
        for (int i = 0; i < n; ++i)
        {
            Min = max(Min, min(pos[i], l - pos[i]));
            Max = max(Max, max(pos[i], l - pos[i]));
        }
        cout << Min << Max << endl;
    }

    return 0;
}