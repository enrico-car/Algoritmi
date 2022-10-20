#include <fstream>
#include <iostream>

using namespace std;

int min(int V[], int startPos, int dim)
{
    int minIndex = startPos;

    for (int i = startPos; i < dim; i = i + 2)
    {
        if (V[i] < V[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void SelectionSort(int V[], int dim)
{
    int temp[2];

    for (int i = 0; i < dim; i = i + 2)
    {
        int minIndex = min(V, i, dim);

        temp[0] = V[i];
        temp[1] = V[i + 1];

        V[i] = V[minIndex];
        V[i + 1] = V[minIndex + 1];

        V[minIndex] = temp[0];
        V[minIndex + 1] = temp[1];
    }
}

int main()
{

    ifstream input("input.txt");

    ofstream out("output.txt");
    int dim;

    input >> dim;

    dim = dim * 2;

    int v[dim];

    for (int i = 0; i < dim; i++)
    {
        input >> v[i];
    }

    SelectionSort(v, dim);

    int end = v[1];

    int gap[] = {end, end, 0};

    for (int i = 2; i < dim; i = i + 2)
    {
        if (v[i] > end)
        {
            int possibleGap = v[i] - end;

            if (possibleGap > gap[2])
            {
                gap[0] = end;
                gap[1] = v[i];
                gap[2] = v[i] - end;
            }
        }

        if (v[i + 1] > end)
        {
            end = v[i + 1];
        }
    }

    if (gap[0] == gap[1])
    {
        out << gap[2];
    }
    else
    {
        out << gap[0] << " " << gap[1] << "\n";
    }
}