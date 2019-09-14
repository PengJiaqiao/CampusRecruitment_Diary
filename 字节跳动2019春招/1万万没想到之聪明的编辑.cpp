/* https://www.nowcoder.com/test/16516564/summary */

#include <iostream>
#include <string>
#include <deque>
using namespace std;

string solution(string &s)
{
    string res;
    deque<char> queue;
    queue.push_back('@');
    queue.push_back('#');
    queue.push_back('$');
    for (char c : s)
    {
        char last = queue.back();
        queue.pop_back();
        char second_last = queue.back();
        queue.pop_back();
        char third_last = queue.back();
        queue.pop_back();
        queue.push_back(third_last);
        queue.push_back(second_last);
        queue.push_back(last);
        if (last == second_last && c == last)
            continue;
        else if (second_last == third_last && c == last)
            continue;
        queue.push_back(c);
    }
    queue.pop_front();
    queue.pop_front();
    queue.pop_front();

    for (char c : queue)
        res.push_back(c);

    return res;
}

int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        string s;
        cin >> s;
        cout << solution(s) << endl;
    }

    return 0;
}