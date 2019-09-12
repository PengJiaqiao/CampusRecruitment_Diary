/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3819&konwledgeId=40 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long int GetCntOfNoGreater(long long int n, long long int m, long long int target)
{
    long long int res = 0;
    for (int i = 1; i <= n; ++i)
        res += min(m, target / i);
    return res;
}

int main()
{
    long long int n, m, k;
    cin >> n >> m >> k;

    long long int low = 1, high = n * m;
    long long int mid = (low + high) / 2;
    long long int res = 0;
    while (1)
    {
        long long int tmp = GetCntOfNoGreater(n, m, mid);
        if (tmp == k)
        {
            res = mid;
            break;
        }
        else if (tmp > k)
        {
            if (GetCntOfNoGreater(n, m, mid - 1) < k)
            {
                res = mid;
                break;
            }
            else
                high = mid - 1;
        }
        else
            low = mid + 1;

        mid = low + (high - low) / 2;
    }

    cout << res << endl;

    return 0;
}