#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, compSize;

public:
    UnionFind(int n) {
        parent.resize(n);
        compSize.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int getParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = getParent(parent[x]);
    }

    void unionSet(int x, int y) {
        int parx = getParent(x), pary = getParent(y);
        if (parx != pary) {
            if (compSize[parx] < compSize[pary]) {
                swap(parx, pary);
            }
            parent[pary] = parx;
            compSize[parx] += compSize[pary];
        }
    }
};

bool hasCycle(int n, vector<vector<int>>& edges) {
    UnionFind dsu(n);
    for (auto& edge: edges) {
        if (dsu.getParent(edge[0]) == dsu.getParent(edge[1])) {
            return true;
        }
        dsu.unionSet(edge[0], edge[1]);
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    for (auto& edge: edges) {
        cin >> edge[0] >> edge[1];
    }
    cout << (hasCycle(n, edges) ? "Cycle" : "No cycle") << "\n";
    return 0;
}