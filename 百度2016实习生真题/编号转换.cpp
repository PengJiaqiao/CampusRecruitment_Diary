/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3821&konwledgeId=40 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Mode1to2(string &s, int idxC)
{
    int column = stoi(s.substr(idxC + 1, s.size() - idxC - 1));

    int level = 0, num = 1;
    while (column > 0)
    {
        level++;
        num *= 26;
        column -= num;
    }
    column += num;

    string res;
    for (int i = 0; i < level; ++i)
    {
        num /= 26;
        char c = column == 0 ? 'Z' : 'A' + (column - 1) / num;
        res.push_back(c);
        column %= num;
    }
    for (int i = 1; i < idxC; ++i)
        res.push_back(s[i]);

    return res;
}

string Mode2to1(string &s)
{
    string res;
    res.push_back('R');

    int i;
    for (i = 1; i < s.size(); ++i)
    {
        if (s[i] - '0' <= 9)
            break;
    }
    for (int j = i; j < s.size(); ++j)
        res.push_back(s[j]);
    res.push_back('C');

    int column = 0;
    for (int j = 0; j < i; ++j)
    {
        column *= 26;
        column += (int)s[j] - 'A';
    }
    column++; // the bottom level (26-branches tree)

    // count the level above
    int num = 1;
    for (int j = 0; j < i - 1; ++j)
    {
        num *= 26;
        column += num;
    }

    return res + to_string(column);
}

string convert(string &s)
{
    if (s[0] == 'R' && s[1] - '0' <= 9)
    {
        for (int i = 2; i < s.size(); ++i)
        {
            if (s[i] == 'C')
                return Mode1to2(s, i);
        }
        return Mode2to1(s);
    }
    else
        return Mode2to1(s);
}

int main()
{
    int T;
    cin >> T;

    vector<string> v(T);
    for (int i = 0; i < T; ++i)
        cin >> v[i];
    for (int i = 0; i < T; ++i)
        cout << convert(v[i]) << endl;

    return 0;
}