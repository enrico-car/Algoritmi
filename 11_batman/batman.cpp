#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <list>

using namespace std;

typedef vector<set<int>> Graph;

void subGraph(Graph &graph, Graph &graphT, int &s, int &d, int &n)
{
    queue<int> queue;
    vector<bool> visited(n, false);
    vector<bool> visited2(n, false);

    queue.push(s);
    int x;
    while (!queue.empty())
    {
        x = queue.front();
        queue.pop();

        if (!visited[x])
        {
            visited[x] = true;
            for (int i : graph[x])
            {
                queue.push(i);
            }
        }
    }

    queue.push(d);
    while (!queue.empty())
    {
        x = queue.front();
        queue.pop();
        if (!visited2[x])
        {
            visited2[x] = true;
            for (int i : graphT[x])
            {
                queue.push(i);
            }
        }
    }

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] && visited2[i])
        {
            continue;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                graph[j].erase(i);
                graphT[j].erase(i);
            }
            graph[i].clear();
            graphT[i].clear();
        }
    }
}

void printAllPathsUtil(Graph &graph, int &u, int &d, vector<bool> &visited, int &counter)
{
    visited[u] = true;
    if (u == d)
    {
        counter++;
    }
    else // If current vertex is not destination
    {
        for (auto i : graph[u])
        {
            if (!visited[i])
            {
                printAllPathsUtil(graph, i, d, visited, counter);
            }
        }
    }

    visited[u] = false;
}

int printAllPaths(Graph &graph, int &s, int &d, int &n)
{
    vector<bool> visited(n, false);
    int counter = 0;
    printAllPathsUtil(graph, s, d, visited, counter);

    return counter;
}

int main()
{
    ifstream input("input.txt");

    ofstream out("output.txt");
    int n, m, s, d;
    input >> n >> m >> s >> d;

    Graph graph;
    Graph graphT;

    graph.resize(n);
    graphT.resize(n);
    int a, b, c;

    for (int i = 0; i < m; i++)
    {
        input >> a >> b;
        graph[a].insert(b);
        graphT[b].insert(a);
    }

    // subGraph(graph, graphT, s, d, n);

    out << printAllPaths(graph, s, d, n);

    return 0;
}