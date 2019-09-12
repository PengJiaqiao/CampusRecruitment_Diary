/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3334&konwledgeId=156 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimeNum(int a, int b)
{
    int res = 0;
    for (int i = a + 1; i < b; ++i)
    {
        if (isPrime(i))
            res++;
    }
    return res;
}

int coeff(int k, int n)
{
    int res = 0;
    int Min = min(k, n - k + 1);
    int Max = max(k, n - k + 1);

    for (int i = 1; i <= Min; ++i)
        res += i;
    for (int i = Min + 1; i <= Max; ++i)
        res += Min;
    for (int i = Max + 1; i <= n; ++i)
        res += i - Max;

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    vector<int> p(n);
    for (int i = 1; i < n; ++i)
        p[i] = countPrimeNum(v[i - 1], v[i]);

    long long int res = 0;
    for (int i = 1; i < n; ++i)
        res += p[i] * coeff(i, n - 1);

    cout << res << endl;

    return 0;
}