#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

std::ostream& operator<<(std::ostream& os, const std::unordered_set<int>& uset)
{
    std::string s;
    s.append("(");
    int size = uset.size();
    std::cout << size << std::endl;
    if (size > 0) {
        s += std::to_string(*uset.begin());
    }
    std::unordered_set<int>::iterator it = uset.begin();
    std::advance(it, 1);
    while(it != uset.end()) {
        s.append(", ").append(std::to_string(*it));
        ++it;
    }
    s.append(")");
    os << s;
    return os;
}

class Graph {
public:
    std::unordered_set <int> v() {
        return vertices;
    }

    int insertNode(int u) {
        if (vertices.find(u) == vertices.end()) {
            vertices.insert(u);
            edges.emplace(u, std::unordered_set<int>());
            return 0;
        }
        else
            return 1;
    }

    int size() {
        return vertices.size();
    }

    void insertEdge(int u, int v) {
        insertNode(u);
        insertNode(v);
        edges.at(u).insert(v);
    }

    std::unordered_set<int> adj(int u) {
        if (vertices.find(u) != vertices.end()) {
            return edges.at(u);
        }
        return std::unordered_set<int>();
    }
private:
    std::unordered_set <int> vertices;
    std::unordered_map <int, std::unordered_set<int> > edges;
};

using namespace std;

int main() {
    

    return 0;
}