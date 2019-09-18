#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int low = -90, high = 90;
    for (int i = 0; i < 6; ++i)
    {
        int mid = low + floor(high - low) / 2;
        if (mid <= n)
        {
            low = mid;
            cout << 1;
        }
        else
        {
            high = mid;
            cout << 0;
        }
    }

    return 0;
}