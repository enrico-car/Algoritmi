#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/**
 * @brief return the sum of a sub matrix
 *
 * @param mat matrix
 * @param ls start line
 * @param le end line
 * @param cs start column
 * @param ce end column
 */
int matrix_sum(int mat[][], int ls, int le, int cs, int ce)
{
    int sum = 0;
    for (int i = ls; i <= le; i++)
    {
        for (int j = cs; j <= ce; j++)
        {
            sum += mat[i][j];
        }
    }

    return sum;
}

int main()
{
    int N, M;
    ifstream in("input.txt");
    in >> N >> M;
    int mat[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            in >> mat[i][j];
        }
    }
    cout << matrix_sum(mat, 0, 0, 1, 1);
    // int somma = 0;

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //     }
    // }
    // cout << maxSoFar;
    return 0;
}