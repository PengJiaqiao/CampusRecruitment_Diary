#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int k = 1024 - N;
    int res = 0;

    res += k / 64;
    k %= 64;
    res += k / 16;
    k %= 16;
    res += k / 4;
    k %= 4;
    res += k;

    cout << res << endl;

    return 0;
}