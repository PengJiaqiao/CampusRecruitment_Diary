/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3354&konwledgeId=40 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
    Node *a[26];
    int cnt;
};

Node *New()
{
    Node *node = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < 26; i++)
        node->a[i] = nullptr;
    node->cnt = 0;
    return node;
}

void insert(Node *node, string &s, int idx)
{
    if (idx >= s.size())
    {
        node->cnt++;
        return;
    }

    int i = s[idx] - 'a';
    if (node->a[i] == nullptr)
        node->a[i] = New();
    insert(node->a[i], s, idx + 1);

    return;
}

int find(Node *root, string &s, int start, int end)
{
    int res = 0;
    Node *node = root;
    for (int idx = start; idx < end; ++idx)
    {
        int i = s[idx] - 'a';
        if (i >= 26)
            break;
        if (i < 0)
            i = s[idx] - 'A';
        if (i >= 26)
            break;

        if (node->a[i] == nullptr)
        {
            if (node->cnt)
                res = idx - start;
            return res;
        }
        else
        {
            if (node->cnt)
                res++;
            node = node->a[i];
        }
    }
    if (node->cnt)
        res = end - start;
    return res;
}

void harmony(Node *root, string &s)
{
    string copy(s);
    for (int i = 0; i < s.size(); ++i)
    {
        int length = find(root, copy, i, copy.size());
        // The length of sensitive word found > 0
        if (length)
        {
            for (int j = i; j < i + length; ++j)
            {
                s[j] = '*';
            }
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    Node *root = New();
    string s;
    while (n--)
    {
        cin >> s;
        insert(root, s, 0);
    }

    vector<string> v;
    while (cin >> s)
    {
        v.push_back(s);
    }

    int start = 0;
    for (int i = 0; i < v.size(); ++i)
        harmony(root, v[i]);

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';

    cout << endl;

    return 0;
}