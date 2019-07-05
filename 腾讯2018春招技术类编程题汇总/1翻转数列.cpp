/* 小Q定义了一种数列称为翻转数列:
给定整数n和m, 满足n能被2m整除。对于一串连续递增整数数列1, 2, 3, 4..., 每隔m个符号翻转一次, 最初符号为'-';。
例如n = 8, m = 2, 数列就是: -1, -2, +3, +4, -5, -6, +7, +8.
而n = 4, m = 1, 数列就是: -1, +2, -3, + 4.
小Q现在希望你能帮他算算前n项和为多少。 */

#include <iostream>
using namespace std;
 
unsigned long long solution(int n, int m) {
    unsigned long long res;
    res = (n / 2) * m;
    return res;
}
 
int main() {
    int n, m;
    cin >> n;
    cin >> m;
    cout << solution(n, m) << endl;
    return 0;
}
