#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
    int counter = 0;

    stack<int> S;
    S.push(s);

    vector<int> level(graph.size(), -1);
    level[s] = 0;

    while (!S.empty())
    {
        int u = S.top();
        S.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int x = graph[u][i];
            S.push(x);
            level[x] = level[u] + 1;
            if (x == t)
            {
                if (level[x] < min)
                {
                    counter = 1;
                    min = level[x];
                }
                else if (level[x] == min)
                {
                    counter++;
                }
            }
        }
    }
    out << min << " " << counter;

    return 0;
}
