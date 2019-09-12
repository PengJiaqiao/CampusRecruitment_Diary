/* https://exercise.acmcoder.com/online/online_judge_ques?ques_id=3373&konwledgeId=40 */

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void addArm(vector<string> &cross, int x, int y, int length)
{
    if (length == 0)
        return;
    cross[x + length][y] = 'o';
    cross[x - length][y] = 'o';
    cross[x][y + length] = 'o';
    cross[x][y - length] = 'o';
    int new_length = length / 3;
    addArm(cross, x + length, y, new_length);
    addArm(cross, x - length, y, new_length);
    addArm(cross, x, y + length, new_length);
    addArm(cross, x, y - length, new_length);
    addArm(cross, x, y, new_length);
    return;
}

void drawCross(int n)
{
    int length = pow(3, n - 1);
    string s(length, ' ');
    vector<string> cross(length, s);

    length /= 2;
    cross[length][length] = 'o';
    addArm(cross, length, length, cross.size() / 3);

    for (int i = 0; i < cross.size(); ++i)
    {
        for (int j = 0; j < cross[0].size(); ++j)
            cout << cross[i][j];
        cout << endl;
    }

    return;
}

int main()
{
    int T;
    cin >> T;

    vector<int> n(T);
    for (int i = 0; i < T; ++i)
        cin >> n[i];
    for (int i = 0; i < T; ++i)
    {
        cout << "Case #" << i + 1 << ":" << endl;
        drawCross(n[i]);
    }

    return 0;
}