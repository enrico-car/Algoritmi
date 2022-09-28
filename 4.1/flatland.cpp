#include <fstream>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print(vector<pair<int, char>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].first << vec[i].second << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    ifstream in("input.txt");
    in >> N;
    vector<pair<int, char>> vec(N), temp(N);
    set<int> set;
    for (int i = 0; i < N; i++)
    {
        vec[i].first = i;
        in >> vec[i].second;
        // cout << vec[i].first << vec[i].second << endl;
    }
    int i;
    for (int j = 1; j < N; j++)
    {
        temp = vec;
        i = j;
        // print(temp);
        while (temp.size() != 1)
        {
            while (i >= temp.size() - 1)
            {
                i--;
            }
            if (temp[i].second == 's')
            {
                temp.erase(temp.begin() + i - 1);
                temp.erase(temp.begin() + i - 1);
            }
            else if (temp[i].second == 'd')
            {
                temp.erase(temp.begin() + i + 1);
                temp.erase(temp.begin() + i);
            }
            else
            {
                cout << "input file not valid" << endl;
                return 1;
            }
            // print(temp);
        }
        set.insert(temp[0].first);
    }
    ofstream out("output.txt");
    out << set.size() << "\n";
    for (auto el : set)
    {
        out << el << " ";
    }

    return 0;
}