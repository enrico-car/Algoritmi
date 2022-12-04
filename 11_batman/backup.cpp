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

void tsDfs(Graph &graph, int u, vector<bool> &visited, stack<int> &stack)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            tsDfs(graph, v, visited, stack);
        }
    }
    stack.push(u);
}

void topSort(Graph &graph, stack<int> &stack, int &n)
{
    vector<bool> visited(n, false);
    for (int u = 0; u < n; u++)
    {
        if (!visited[u])
        {
            tsDfs(graph, u, visited, stack);
        }
    }
}

void ccdfs(Graph &graph, int &counter, int &u, vector<int> &id)
{

    id[u] = counter;
    for (int v : graph[u])
    {
        if (id[v] == 0)
        {
            ccdfs(graph, counter, v, id);
        }
        else if (id[v] != counter)
        {
            cout << "mostro tra" << u << "-" << v << endl;
        }
    }
}

void cc(Graph &graph, stack<int> &stack, vector<int> &id, int &n)
{
    int counter = 0;
    int u;
    while (!stack.empty())
    {
        u = stack.top();
        stack.pop();
        if (id[u] == 0 && !graph[u].empty())
        {
            counter++;
            ccdfs(graph, counter, u, id);
        }
    }
}

void bfs(Graph &graph, int &s, int &d, int &n)
{
    int min = 50;
    int counter = 0;

    stack<int> S;
    S.push(s);

    vector<int> level(graph.size(), -1);
    level[s] = 0;

    while (!S.empty())
    {
        int u = S.top();
        S.pop();
        cout << "node " << u << endl;
        for (int i : graph[u])
        {
            cout << "push " << i << endl;
            // S.push(i);
            // level[i] = level[i] + 1;
            // if (i == d)
            // {
            //     if (level[i] < min)
            //     {
            //         counter = 1;
            //         min = level[i];
            //     }
            //     else if (level[i] == min)
            //     {
            //         counter++;
            //     }
            // }
        }
        // cout << min << " " << counter;
    }
}

void printAllPathsUtil(Graph &graph, int &u, int &d, vector<bool> &visited, vector<int> &path, int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    // path[path_index] = u;
    // path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        // for (int i = 0; i < path_index; i++)
        //     cout << path[i] << " ";
        // cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current
        // vertex

        for (auto i : graph[u])
        {
            if (!visited[i])
            {
                printAllPathsUtil(graph, i, d, visited, path, path_index);
            }
        }
    }

    // Remove current vertex from path[] and mark it as
    // unvisited
    path_index--;
    visited[u] = false;
}

void printAllPaths(Graph &graph, int &s, int &d, int &n)
{
    // Mark all the vertices as not visited
    vector<bool> visited(n, false);
    // Create an array to store paths
    vector<int> path(n);

    int path_index = 0; // Initialize path[] as empty

    // Call the recursive helper function to print all paths
    printAllPathsUtil(graph, s, d, visited, path, path_index);
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

    subGraph(graph, graphT, s, d, n);

    // stack<int> stack;
    // vector<int> id(n, 0);
    // topSort(graph, stack, n);
    // cc(graphT, stack, id, n);

    printAllPaths(graph, s, d, n);

    return 0;
}