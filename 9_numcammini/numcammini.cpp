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

    return 0;
}