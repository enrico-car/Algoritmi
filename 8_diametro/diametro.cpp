#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ifstream input("input.txt");

    ofstream out("output.txt");
    int n, m, s;
    input >> n >> m;

    vector<vector<int>> graph;
    vector<bool> visited(n);
    vector<int> level(n);

    queue<int> queue;

    graph.resize(n);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        input >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int max = -1;

    for (int z = 0; z < n; z++)
    {
        visited = vector<bool>(n, false);
        level = vector<int>(n, -1);

        queue.push(z);
        level[z] = 0;
        int x;
        while (!queue.empty())
        {
            x = queue.front();
            queue.pop();
            if (!visited[x])
            {
                visited[x] = true;
                for (int i = 0; i < graph[x].size(); i++)
                {
                    if (level[graph[x][i]] == -1)
                    {
                        level[graph[x][i]] = level[x] + 1;
                    }
                    queue.push(graph[x][i]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (level[i] > max)
            {
                max = level[i];
            }
        }
    }

    out << max;

    return 0;
}