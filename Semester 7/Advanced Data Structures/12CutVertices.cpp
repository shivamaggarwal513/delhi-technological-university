#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void getCutVertices(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& disc, 
    vector<int>& low, vector<bool>& isCutVertex, int& time, int curr, int prev) {
    int numChild = 0;
    visited[curr] = true;
    disc[curr] = low[curr] = ++time;
    for (int next: graph[curr]) {
        if (!visited[next]) {
            numChild++;
            getCutVertices(graph, visited, disc, low, isCutVertex, time, next, curr);
            low[curr] = min(low[curr], low[next]);
            if (prev != -1 && low[next] >= disc[curr]) {
                isCutVertex[curr] = true;
            }
        } else if (next != prev) {
            low[curr] = min(low[curr], disc[next]);
        }
    }
    if (prev == -1 && numChild > 1) {
        isCutVertex[curr] = true;
    }
}

int countCutVertices(int n, vector<vector<int>>& edges) {
    int time = 0;
    vector<vector<int>> graph(n);
    vector<int> disc(n), low(n);
    vector<bool> visited(n), isCutVertex(n);
    for (auto& edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            getCutVertices(graph, visited, disc, low, isCutVertex, time, i, -1);
        }
    }
    return count(isCutVertex.begin(), isCutVertex.end(), true);
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(e, 2));
    for (auto& edge: edges) {
        cin >> edge[0] >> edge[1];
    }
    cout << "Cut Vertices: " << countCutVertices(n, edges) << "\n";
    return 0;
}

/*
5 5
0 1 1 2 2 0 2 3 3 4
*/