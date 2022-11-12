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
    input >> n >> m >> s;

    vector<vector<int>> graph;
    vector<bool> visited(n, false);
    queue<int> queue;

    graph.resize(n);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        input >> a >> b;
        graph[a].push_back(b);
    }

    queue.push(s);
    int x;
    int counter = 0;
    while (!queue.empty())
    {
        x = queue.front();
        queue.pop();
        if (!visited[x])
        {
            visited[x] = true;
            counter++;
            for (int i = 0; i < graph[x].size(); i++)
            {
                queue.push(graph[x][i]);
            }
        }
    }

    out << counter;

    return 0;
}