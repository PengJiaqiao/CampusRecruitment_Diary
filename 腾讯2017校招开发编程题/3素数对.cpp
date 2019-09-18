#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
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

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 2; i < n - 1; ++i)
    {
        if (isPrime(i))
            v.push_back(i);
    }

    unordered_map<int, int> M;
    int res = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (M.find(v[i]) == M.end())
            M[n - v[i]] = v[i];
        else
            res++;
    }

    if (n % 2 == 0)
    {
        if (M.find(n / 2) != M.end())
            res++;
    }

    cout << res << endl;

    return 0;
}