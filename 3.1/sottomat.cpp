#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int maxVec(int arr[], int dim)
{
	int maxHere = 0;
	int maxSoFar = 0;
	for (int i = 0; i < dim; i++)
	{
		maxHere = max(maxHere + arr[i], 0);
		maxSoFar = max(maxSoFar, maxHere);
	}
	return maxSoFar;
}

void cleanVector(int arr[], int dim)
{
	for (int j = 0; j < dim; j++)
	{
		arr[j] = 0;
	}
}

int main()
{
	int N, M;
	ifstream in("input.txt");
	in >> N >> M;
	int mat[N][M];
	int vet[M];

	int max = 0;
	int maxtemp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			in >> mat[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		cleanVector(vet, M);
		for (int j = i; j < N; j++)
		{
			for (int x = 0; x < M; x++)
			{
				vet[x] += mat[j][x];
			}
			maxtemp = maxVec(vet, M);
			if (max < maxtemp)
			{
				max = maxtemp;
			}
		}
	}
	ofstream out("output.txt");
	out << max << "\n";
	return 0;
}