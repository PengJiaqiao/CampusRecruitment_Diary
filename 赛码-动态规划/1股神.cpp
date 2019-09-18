/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=1664&konwledgeId=134 */

#include <iostream>
using namespace std;

int solution(int n)
{
    int err = 0;
    int i = n;
    int j = 2;
    while (i > j)
    {
        err += 2;
        i -= j;
        j++;
    }

    return n - err;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << solution(n) << endl;
    }

    return 0;
}