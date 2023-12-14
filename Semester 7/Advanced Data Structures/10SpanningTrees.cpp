#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> minorMatrix(vector<vector<int>>& matrix, int i, int j) {
    int n = matrix.size();
    vector<vector<int>> minor(n - 1, vector<int>(n - 1));
    for (int r = 0; r < n; r++) {
        if (r != i) {
            for (int c = 0; c < n; c++) {
                if (c != j) {
                    minor[r - (r > i)][c - (c > j)] = matrix[r][c];
                }
            }
        }
    }
    return minor;
}

int determinant(vector<vector<int>> matrix) {
    int n = matrix.size(), det = 0;
    if (n == 1) {
        return matrix[0][0];
    }
    for (int c = 0; c < n; c++) {
        det += (c & 1 ? -1 : 1) * matrix[0][c] * determinant(minorMatrix(matrix, 0, c));
    }
    return det;
}

int countSpanningTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> laplacian(n, vector<int>(n));
    for (auto& e: edges) {
        laplacian[e[0]][e[0]]++;
        laplacian[e[1]][e[1]]++;
        laplacian[e[0]][e[1]] = laplacian[e[1]][e[0]] = -1;
    }
    for (int r = 0; r < n; r++) {
        laplacian[r].pop_back();
    }
    laplacian.pop_back();
    return determinant(laplacian);
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    for (auto& edge: edges) {
        cin >> edge[0] >> edge[1];
    }
    cout << "Spanning Trees: " << countSpanningTrees(n, edges) << "\n";
    return 0;
}