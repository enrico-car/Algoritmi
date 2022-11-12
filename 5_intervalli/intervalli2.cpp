#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Interval
{
    int start, end;
};

int main()
{
    vector<Interval> v;
    // vector<int> v;
    ifstream input("input.txt");

    ofstream out("output.txt");
    int dim;

    input >> dim;
    // dim *= 2;

    int a, b;
    Interval t;
    for (int i = 0; i < dim; i++)
    {
        input >> t.start >> t.end;
        v.push_back(t);
    }

    sort(v.begin(), v.end(),
         [](Interval i1, Interval i2)
         {
             return (i1.start < i2.start);
         });

    int end = v[0].end;
    int gap[] = {end, end, 0};

    for (int i = 1; i < dim; i++)
    {
        if (v[i].start > end)
        {
            int possibleGap = v[i].start - end;

            if (possibleGap > gap[2])
            {
                gap[0] = end;
                gap[1] = v[i].start;
                gap[2] = v[i].start - end;
            }
        }

        if (v[i].end > end)
        {
            end = v[i].end;
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

    return 0;
}