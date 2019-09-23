#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> v_sorted(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    copy(v.begin(), v.end(), v_sorted.begin());
    sort(v_sorted.begin(), v_sorted.end());
    int i = 0;
    for (int num : v)
    {
        if (num == v_sorted[i])
            ++i;
    }
    cout << N - i << endl;

    return 0;
}