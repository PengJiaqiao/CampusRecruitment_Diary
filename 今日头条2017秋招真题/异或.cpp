/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3338&konwledgeId=158 */

#include <iostream>
#include <vector>
using namespace std;

int n, m, bit[32];
long long int ans;

struct node
{
    node *a[2];
    int cnt;
};

node *New()
{
    node *t = (node *)malloc(sizeof(node));
    t->a[0] = NULL;
    t->a[1] = NULL;
    t->cnt = 0;
    return t;
}

void Insert(node *root, int cur, int num)
{
    if (cur < 0)
        return;
    if (num & bit[cur])
    {
        if (root->a[1] == NULL)
        {
            root->a[1] = New();
            (root->a[1]->cnt)++;
            Insert(root->a[1], cur - 1, num);
        }
        else
        {
            (root->a[1]->cnt)++;
            Insert(root->a[1], cur - 1, num);
        }
    }
    else
    {
        if (root->a[0] == NULL)
        {
            root->a[0] = New();
            (root->a[0]->cnt)++;
            Insert(root->a[0], cur - 1, num);
        }
        else
        {
            (root->a[0]->cnt)++;
            Insert(root->a[0], cur - 1, num);
        }
    }
}

void query(node *root, int cur, int num)
{
    if (cur < 0 || root == NULL)
        return;
    if (m & bit[cur])
    {
        if (num & bit[cur])
            query(root->a[0], cur - 1, num);
        else
            query(root->a[1], cur - 1, num);
    }
    else
    {
        if (num & bit[cur])
        {
            if (root->a[0] != NULL)
                ans = ans + root->a[0]->cnt;
            query(root->a[1], cur - 1, num);
        }
        else
        {
            if (root->a[1] != NULL)
                ans = ans + root->a[1]->cnt;
            query(root->a[0], cur - 1, num);
        }
    }
}

int main()
{
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    bit[0] = 1;
    for (int i = 1; i < 32; ++i)
        bit[i] = bit[i - 1] * 2;

    node *root = New();
    for (int i = 0; i < n; ++i)
        Insert(root, 31, A[i]);

    ans = 0;
    for (int i = 0; i < n; ++i)
        query(root, 31, A[i]);

    cout << ans / 2 << endl;

    return 0;
}