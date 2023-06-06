#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// output overload for vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    bool nf = false;
    os << "{";
    for (const T& x: v) {
        os << (nf ? "," : (nf = true, "")) << x;
    }
    os << "}";
    return os;
}

vector<int> distance_vector_routing(int n, vector<vector<int>>& edges, int s) {
    vector<int> distance(n, INT_MAX);
    distance[s] = 0;
    for (int i = 1; i < n; i++) {
        for (auto& e: edges) {
            if (distance[e[0]] != INT_MAX) {
                distance[e[1]] = min(distance[e[1]], distance[e[0]] + e[2]);
            }
            if (distance[e[1]] != INT_MAX) {
                distance[e[0]] = min(distance[e[0]], distance[e[1]] + e[2]);
            }
        }
    }
    return distance;
}

int main() {
    int n, e;
    cout << "Number of routers: "; cin >> n;
    cout << "Number of edges: "; cin >> e;
    vector<vector<int>> edges(e, vector<int>(3));
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << i << ": " << distance_vector_routing(n, edges, i) << "\n";
    }
    return 0;
}

/*
4 4
0 1 8
0 3 5
1 2 2
2 3 3

5 6
0 1 1
0 2 5
1 2 3
1 4 9
2 3 4
3 4 2
*/