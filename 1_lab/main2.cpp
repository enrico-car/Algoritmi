
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAXN 1000000

int main()
{
    int N;
    int arr[MAXN];
    int maxSoFar = 0;
    int maxHere = 0;
    ifstream in("input.txt");
    in >> N;

    for (int i = 0; i < N; i++)
    {
        in >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        maxHere = max(maxHere + arr[i], 0);
        maxSoFar = max(maxSoFar, maxHere);
    }
    ofstream out("output.txt");
    out << maxSoFar << "\n";
    return 0;
}
