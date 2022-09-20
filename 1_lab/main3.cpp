
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAXN 2000

int main()
{
    int N, M;
    int a = 0;
    int arr[2000][2000];

    ifstream in("input.txt");
    in >> N >> M;
    cout << N << " " << M << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            in >> a;
            // cout << a << " ";
            arr[i][j] = a;
            // cout << arr[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j];
        }
    }

    // ofstream out("output.txt");
    // out << maxSoFar << "\n";
    return 0;
}
