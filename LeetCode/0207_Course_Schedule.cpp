#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (vector<int> prerequisite : prerequisites)
            graph[prerequisite[0]].push_back(prerequisite[1]);

        for (int i = 0; i < numCourses; ++i)
        {
            queue<int> q;
            for (int j : graph[i])
                q.push(j);
            unordered_map<int, int> M;
            while (!q.empty())
            {
                int course = q.front();
                q.pop();
                if (M.find(course) == M.end())
                    M[course] = 1;
                if (course == i)
                    return false;
                for (int j : graph[course])
                {
                    if (M.find(j) == M.end())
                        q.push(j);
                }
            }
        }
        return true;
    }
};