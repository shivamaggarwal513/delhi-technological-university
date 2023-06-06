#include <iostream>
#include <vector>
#include <set>
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

vector<int> link_state_routing(int n, vector<vector<vector<int>>>& edges, int s) {
    vector<int> distance(n, INT_MAX);
    set<vector<int>> pending;
    pending.insert({0, s});
    distance[s] = 0;
    while (!pending.empty()) {
        vector<int> x = *pending.begin();
        pending.erase(pending.begin());
        for (auto& y: edges[x[1]]) {
            if (distance[x[1]] + y[1] < distance[y[0]]) {
                if (distance[y[0]] != INT_MAX) {
                    pending.erase(pending.find({distance[y[0]], y[0]}));
                }
                distance[y[0]] = distance[x[1]] + y[1];
                pending.insert({distance[y[0]], y[0]});
            }
        }
    }
    return distance;
}

int main() {
    int n, e, s, d, w;
    cout << "Number of routers: "; cin >> n;
    cout << "Number of edges: "; cin >> e;
    vector<vector<vector<int>>> edges(n);
    for (int i = 0; i < e; i++) {
        cin >> s >> d >> w;
        edges[s].push_back({d, w});
        edges[d].push_back({s, w});
    }
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << i << ": " << link_state_routing(n, edges, i) << "\n";
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