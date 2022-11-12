#include <iostream>
#include <fstream>

using namespace std;

int scambioPesato(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;

    return v[i] + v[j];
}

void main()
{
    ifstream input("input.txt");

    ofstream out("output.txt");
    int dim;

    input >> dim;

    int v[dim];

    for (int i = 0; i < dim; i++)
    {
        input >> v[i];
    }
}