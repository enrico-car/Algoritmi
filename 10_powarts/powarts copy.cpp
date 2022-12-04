#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Link
{
    int node;
    int weight;
};

struct CoolNode
{
    int node;
    int freq;
};

bool sortCool(CoolNode i, CoolNode j) { return (i.freq > j.freq); }

int check(vector<vector<Link>> &graph, int n, int p, vector<bool> &killed, int devil)
{

    vector<int> roadWeight(n, -1);
    queue<int> queue;

    queue.push(p);
    roadWeight[p] = 0;
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
                    // cout << "node" << x << " is killed so, kill " << u.node << endl;
                }
                else if (!killed[x] && u.node != devil)
                {
                    killed[u.node] = false;
                    // cout << "node" << x << " is alive so, live " << u.node << endl;
                }
                roadWeight[u.node] = u.weight + roadWeight[x];
                // cout << "node:" << u.node << " roadWeight:" << roadWeight[u.node] << " killed:" << killed[u.node] << endl;
                queue.push(u.node);
            }
            else if (u.weight + roadWeight[x] == roadWeight[u.node] && !killed[x] && killed[u.node] && u.node != devil)
            {
                killed[u.node] = false;
                // cout << "gesus node: " << u.node << endl;
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

    queue<int> queue;
    CoolNode coolNode;
    coolNode.freq = -1;
    vector<CoolNode> visited(n);

    for (int i = 0; i < n; i++)
    {
        coolNode.node = i;
        visited[i] = coolNode;
    }

    queue.push(p);
    int x;
    while (!queue.empty())
    {
        x = queue.front();
        queue.pop();
        if (visited[x].freq == -1)
        {
            // cout << "visito" << x << endl;
            for (int i = 0; i < graph[x].size(); i++)
            {
                visited[x].freq++;
                queue.push(graph[x][i].node);
            }
        }
    }

    sort(visited.begin(), visited.end(), sortCool);

    // for (auto i : visited)
    // {
    //     cout << "nodo: " << i.node << " freq: " << i.freq << endl;
    // }

    vector<bool> killed(n);
    vector<bool> save(n, false);
    int count = 0;
    int temp;
    for (int i = 0; i <= n / 2; i++)
    {
        killed = vector<bool>(n, false);
        if (visited[i].node != p && visited[i].freq > 1)
        {
            temp = check(graph, n, p, killed, visited[i].node);
            if (temp > count)
            {
                count = temp;
                save = vector<bool>(killed);
            }
        }
    }

    out << count;

    for (int i = 0; i < n; i++)
    {
        if (save[i] == true)
        {
            out << "\n"
                << i;
        }
    }

    return 0;
}