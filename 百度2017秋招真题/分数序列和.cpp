/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3371&konwledgeId=40 */

#include <iostream>
using namespace std;

int main()
{
    int k, n;
    cin >> k;

    while (k)
    {
        k--;
        cin >> n;
        double a = 2, b = 1, c;
        double sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += a / b;
            c = b;
            b = a;
            a = a + c;
        }
        printf("%.4f\n", sum);
    }

    return 0;
}