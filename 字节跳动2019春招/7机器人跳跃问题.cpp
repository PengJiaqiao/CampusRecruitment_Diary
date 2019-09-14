#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool reachEnd(vector<int> &H, int E, int Max)
{
    for (int h : H)
    {
        E = 2 * E - h;
        if (E >= Max)
            return true;
        if (E < 0)
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    int Max = 0;
    vector<int> H(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> H[i];
        Max = max(Max, H[i]);
    }

    int low = 0, high = Max;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (reachEnd(H, mid, Max))
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << low << endl;

    return 0;
}