// 暴力解AC 10%

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            v.push_back(a[i] + a[j]);
        }
    }

    int res = v[0];
    for (int i = 1; i < v.size(); ++i)
        res ^= v[i];
    cout << res << endl;

    return 0;
}