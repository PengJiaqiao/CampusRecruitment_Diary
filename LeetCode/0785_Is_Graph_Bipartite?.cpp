#include <vector>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); ++i)
        {
            if (color[i] == -1 && !isBipartite(i, 0, graph, color))
                return false;
        }
        return true;
    }

private:
    bool isBipartite(int curNode, int curColor, vector<vector<int>> &graph, vector<int> &color)
    {
        if (color[curNode] != -1)
            return curColor == color[curNode];
        color[curNode] = curColor;
        for (int next : graph[curNode])
        {
            if (!isBipartite(next, 1 - curColor, graph, color))
                return false;
        }
        return true;
    }
};