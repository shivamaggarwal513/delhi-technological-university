#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string hillEncrypt(string s, vector<vector<int>>& key) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    s += string(s.size() % key.size(), 'Z');
    int sn = s.size(), kn = key.size();
    string hill;
    for (int i = 0; i < sn; i += kn) {
        for (int c = 0; c < kn; c++) {
            int sum = 0;
            for (int r = 0; r < kn; r++) {
                sum = (sum + key[r][c] * (s[i + r] - 'A')) % 26;
            }
            hill.push_back(sum + 'A');
        }
    }
    return hill;
}

int main() {
    int kn;
    string s;
    cout << "Enter string: "; cin >> s;
    cout << "Enter key matrix size: "; cin >> kn;
    vector<vector<int>> key(kn, vector<int>(kn));
    cout << "Enter key matrix\n";
    for (int i = 0; i < kn; i++) {
        for (int j = 0; j < kn; j++) {
            cin >> key[i][j];
        }
    }
    string encrypted = hillEncrypt(s, key);
    cout << "Encrypted string: " << encrypted << "\n";
    return 0;
}