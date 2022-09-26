#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int N, M;
    ifstream in("input.txt");
    in >> N >> M;
    // cout << N << M;
    int mat[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            in >> mat[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << mat[i][j];
        }
    }

    return 0;
}