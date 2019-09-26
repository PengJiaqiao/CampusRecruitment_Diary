#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    long long int sum = 0;
    for (int i = 0; i < M; ++i)
        sum += v[i];

    long long int Max = sum;
    for (int i = M, j = 0; i < N; ++i, ++j)
    {
        sum -= v[j];
        sum += v[i];
        Max = max(Max, sum);
    }

    double res = (double)Max / M;
    res += 0.0001;
    printf("%.3f\n", res);

    return 0;
}