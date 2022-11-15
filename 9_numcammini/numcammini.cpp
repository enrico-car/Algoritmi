#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(const vector<vector<int>> &graph, int s,const  int &t, int &min, int &len, int level = 0)
{
    int v;

    if (s == t)
    {
        if (level < min)
        {
            min = level;
            len = 1;
        }
        else if (level == min)
        {
            len++;
        }
    }
    for (int i = 0; i < graph[s].size(); i++)
    {
        v = graph[s][i];

        dfs(graph, v, t, min, len, level + 1);
    }
}

int main()
{
    ifstream input("input.txt");

    ofstream out("output.txt");
    int n, m, s, t;
    input >> n >> m >> s >> t;

    vector<vector<int>> graph;

    graph.resize(n);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        input >> a >> b;
        graph[a].push_back(b);
    }

    int min = m;
    int len = 1;

    dfs(graph, s, t, min, len);
    out << min << " " << len;

    return 0;
}