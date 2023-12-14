#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isEulerian(int n, vector<vector<int>>& edges) {
    vector<int> degree(n);
    for (auto& e: edges) {
        degree[e[0]]++;
        degree[e[1]]++;
    }
    int c = count_if(degree.begin(), degree.end(), [](int x) { return x & 1; });
    return c == 0 || c == 2;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    for (auto& e: edges) {
        cin >> e[0] >> e[1];
    }
    cout << (isEulerian(n, edges) ? "Eulerian Graph" : "Not Eulerian Graph") << "\n";
    return 0;
}