#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, D;
    cin >> N >> D;

    vector<int> pos(N);
    for (int i = 0; i < N; ++i)
        cin >> pos[i];

    if (N < 3)
        cout << 0 << endl;
    else
    {
        long long int res = 0;
        int end = 2;
        for (int i = 0; i < N - 2; ++i)
        {
            while (end < N && pos[end] - pos[i] <= D)
                end++;
            end--;
            if (end < i + 2 || pos[end] - pos[i] > D)
                continue;

            res += (long long int)(end - i) * (end - i - 1) / 2;
            res %= 99997867;
        }
        cout << res << endl;
    }

    return 0;
}