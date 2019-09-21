// 送分题

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> n(N);
    vector<int> k(K);
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        n[i] = make_pair(a, b);
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> k[i];
    }

    sort(n.begin(), n.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

    for (int k_ : k)
        cout << n[k_].second << endl;

    return 0;
}