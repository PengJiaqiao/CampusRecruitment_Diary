/* 小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力 */

#include<iostream>
using namespace std;
 
int solution(int n, int m) {
    int power2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
    if(n==1) return m;
    int alignable = m - n, res = 1, MAX_INDEX = 16;
    for(int i = MAX_INDEX - 1; i >= 0; --i) if(alignable>=power2[i]-1) {
        if(i > 0) res += power2[i - 1];
        int assigned = 0;
        if(i>n)
            assigned = power2[i] - power2[i-n];
        else
            assigned = power2[i] - 1;
        alignable -= assigned;
    }
    return res;
}
 
int main() {
    int n, m;
    cin >> n;
    cin >> m;
    cout << solution(n, m) << endl;
    return 0;
}
