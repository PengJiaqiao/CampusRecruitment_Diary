#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    vector<int> dis(N - 1);
    int sum = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        dis[i] = abs(v[i + 1] - v[i]);
        sum += dis[i];
    }

    int diff = 0, tmp;
    for (int i = 1; i < N - 1; ++i)
    {
        tmp = dis[i - 1] + dis[i] - abs(v[i + 1] - v[i - 1]);
        diff = max(diff, tmp);
    }

    cout << sum - diff << endl;

    return 0;
}