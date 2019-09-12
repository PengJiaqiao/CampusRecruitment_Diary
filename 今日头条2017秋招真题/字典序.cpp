/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3341&konwledgeId=158 */

#include <iostream>
using namespace std;

struct Node
{
    Node *next[10];
    long long int val;
};

Node *New(long long int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < 10; ++i)
        node->next[i] = nullptr;
    node->val = val;
    return node;
}

// total number of child nodes with val < n
long long int getCntOfChild(long long int val, long long int n)
{
    long long int res = 1; // including itself
    for (long long int level=1) {

    }

    return res;
}

int main()
{
    long long int n, m;
    cin >> n >> m;

    long long int res = 1;
    while (m)
    {
        long long int num = getCntOfChild(res, n);
        if(m>num) {
            m-= num;
            res++;
        }
        else {
            m--;
            res *=10;
        }
    }

    res/=10;
    cout << res << endl;

    return 0;
}