/* 牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
他们的得分等于他们抽到的纸牌数字总和。
现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。 */

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(int n, vector<int>& a) {
    sort(a.begin(), a.end(), [&a](int i, int j) { return i > j; });
    int res = 0, idx = 0;
    if(n % 2 == 1) res += a.back();
    for(int i = 0; i < n / 2; ++i) {
        res += a[idx] - a[++idx];
        ++idx;
    }
    return res;
}
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solution(n, a) << endl;
    return 0;
}
