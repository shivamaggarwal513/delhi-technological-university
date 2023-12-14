#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> floydWarshall(int n, vector<vector<int>>& edges) {
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }
    for (auto& e: edges) {
        cost[e[0]][e[1]] = cost[e[1]][e[0]] = min(cost[e[0]][e[1]], e[2]);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][k] != INT_MAX && cost[k][j] != INT_MAX) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }
    return cost;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e, vector<int>(3));
    for (auto& e: edges) {
        cin >> e[0] >> e[1] >> e[2];
    }
    vector<vector<int>> cost = floydWarshall(n, edges);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cost[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}

/*
5 8
0 1 4
0 2 2
0 3 5
0 4 1
1 2 1
1 4 6
2 3 3
3 4 4
*/