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

int check(vector<vector<Link>> graph, int n, int p, vector<bool> killed, int devil)
{

    vector<int> roadWeight(n, -1);
    queue<int> queue;
    queue.push(devil);
    roadWeight[devil] = 0;
    int x;
    killed[devil] = true;

    while (!queue.empty())
    {
        x = queue.front();
        queue.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            Link u = graph[x][i];

            if (roadWeight[u.node] == -1 || u.weight + roadWeight[x] < roadWeight[u.node])
            {
                if (killed[x] && u.node != p)
                {
                    killed[u.node] = true;
                    cout << "node" << x << " is killed so, kill " << u.node << endl;
                }
                else if (!killed[x] && u.node != devil)
                {
                    killed[u.node] = false;
                    cout << "node" << x << " is alive so, live " << u.node << endl;
                }
                roadWeight[u.node] = u.weight + roadWeight[x];
                cout << "node:" << u.node << " roadWeight:" << roadWeight[u.node] << " killed:" << killed[u.node] << endl;
                queue.push(u.node);
            }
            else if (u.weight + roadWeight[x] == roadWeight[u.node] && !killed[x] && killed[u.node] && u.node != devil)
            {
                killed[u.node] = false;
                cout << "gesus node: " << u.node << endl;
                queue.push(u.node);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < killed.size(); i++)
    {
        if (killed[i] == true)
        {
            count++;
        }
    }
    return count;
}

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
        link.node = a;
        graph[b].push_back(link);
    }

    vector<bool> killed(n);
    vector<bool> save(n, false);

    for (int i = 0; i < n; i++)
    {
        killed = vector<bool>(n, false);
        if (i != p)
        {
            cout << "devil: " << i << " count:\n " << check(graph, n, p, killed, i) << endl;
        }
    }

    return 0;
}