/* 小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。 */

#include<iostream>
using namespace std;
 
long long c[105][105];
const int mod = 1000000007;
  
void init()   //计算组合数
{
    c[0][0] = 1;
    for(int i = 1; i <= 100; ++i)
    {
        c[i][0] = 1;
        for(int j = 1; j <= 100; ++j)
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}
 
int solution(int k, int a, int x, int b, int y) {
    init();
    long long tmp;
    for(int i = 0;i <= x;i++)
    {
        if(i * a <= k && (k - i * a) % b == 0 && (k - i * a) / b <= y) //满足题目的判断条件
        {
            tmp = (tmp + (c[x][i] * c[y][(k - i * a) / b]) % mod) % mod;
        }
    }
    return tmp;
}
 
int main() {
    int K;
    cin >> K;
    int A, X, B, Y;
    cin >> A >> X >> B >> Y;
    cout << solution(K, A, X, B, Y) << endl;
    return 0;
}
