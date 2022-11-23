#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Link
{
    int node;
    int weight;
};

int main()
{
    ifstream input("input.txt");

    ofstream out("output.txt");
    int n, m, p;
    input >> n >> m >> p;

    vector<vector<Link>> graph;

    graph.resize(n);
    int a, b, c;
    Link link;
    for (int i = 0; i < m; i++)
    {
        input >> a >> b >> c;
        link.node = b;
        link.weight = c;
        graph[a].push_back(link);
    }

    vector<int> roadWeight(n, -1);
    vector<bool> visited(n, false);
    vector<bool> killed(n, false);

    queue<int> queue;

    queue.push(p);
    roadWeight[p] = 0;
    int x;
    int devil = 1;
    killed[devil] = true;

    while (!queue.empty())
    {
        x = queue.front();
        queue.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            Link u = graph[x][i];

            // if (!killed[x] && u.weight + roadWeight[x] == roadWeight[u.node])
            // {
            //     killed[u.node] = false;
            // }
            if (roadWeight[u.node] == -1 || u.weight + roadWeight[x] < roadWeight[u.node])
            {
                if (killed[x])
                {
                    killed[u.node] = true;
                    cout << "node" << x << " is killed so, kill " << u.node << endl;
                }
                roadWeight[u.node] = u.weight + roadWeight[x];
                cout << "node:" << u.node << " roadWeight:" << roadWeight[u.node] << " killed:" << killed[u.node] << endl;
                queue.push(u.node);
            }
            if (u.weight + roadWeight[x] == roadWeight[u.node] && !killed[x])
            {
                killed[u.node] = false;
                cout << "gesus" << endl;
            }
        }
    }

    // for (int i = 0; i < killed.size(); i++)
    // {
    //     if (killed[i] == 1)
    //     {
    //         cout << "morto:" << i << endl;
    //     }
    // }

    return 0;
}