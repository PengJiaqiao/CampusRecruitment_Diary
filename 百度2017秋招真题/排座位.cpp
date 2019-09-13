/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3370&konwledgeId=40 */

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int m)
{
    if (n < 2 * m)
        return 0;

    // convert to A(n-m+1, m) - A(m,2)*A(n-m-1,m-2)
    long long int res = 1;
    for (int i = 0; i < m; ++i)
    {
        res *= (long long int)n - m + 1 - i;
        res %= 1000000007;
    }
    long long int minus = m >= 2 ? (m * (m - 1)) : 0;
    for (int i = 0; i < m - 2; ++i)
    {
        minus *= (long long int)n - m - 1 - i;
        minus %= 1000000007;
    }

    res -= minus;
    res = res > 0 ? res : res + 1000000007;
    return res;
}

int main()
{
    int T;
    cin >> T;
    vector<pair<int, int>> nm(T);
    for (int i = 0; i < T; ++i)
        cin >> nm[i].first >> nm[i].second;

    for (int i = 0; i < T; ++i)
        cout << solution(nm[i].first, nm[i].second) << endl;

    return 0;
}