#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int K;
    cin >> K;

    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            int sum = v[i] + v[j];
            int idx = j + 1;
            while (idx < n && (sum + v[idx]) < K)
            {
                idx++;
            }
            res += idx - j - 1;
        }
    }

    cout << res << endl;

    return 0;
}