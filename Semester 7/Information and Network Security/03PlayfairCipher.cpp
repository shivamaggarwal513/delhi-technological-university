#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void printPlayfairCipher(vector<vector<char>>& matrix, string& s, string& t) {
    int n = s.size();
    cout << "\nPlayfair Matrix: \n";
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            cout << matrix[r][c];
            if (matrix[r][c] == 'I') {
                cout << "/J";
            }
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "\nDigrams  : ";
    for (int i = 0; i < n; i++) {
        cout << s[i] << (i & 1 ? " " : "");
    }
    cout << "\nPlayfair : ";
    for (int i = 0; i < n; i++) {
        cout << t[i] << (i & 1 ? " " : "");
    }
    cout << "\n";
}

vector<vector<char>> generatePlayfairMatrix(string key) {
    int kn = key.size(), i = 0;
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    vector<vector<char>> matrix(5, vector<char>(5));
    vector<bool> taken(26);
    taken[9] = true;
    for (int ki = 0; ki < kn && i < 25; ki++) {
        if (!taken[key[ki] - 'A']) {
            matrix[i / 5][i % 5] = key[ki];
            taken[key[ki] - 'A'] = true;
            i++;
        }
    }
    for (int ti = 0; ti < 26 && i < 25; ti++) {
        if (!taken[ti]) {
            matrix[i / 5][i % 5] = ti + 'A';
            taken[ti] = true;
            i++;
        }
    }
    return matrix;
}

string generateDigrams(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for (int i = 0; i < s.size() - 1; i += 2) {
        if (s[i] == s[i + 1]) {
            s.insert(s.begin() + i + 1, s[i] != 'Z' ? 'Z' : 'Y');
        }
    }
    if (s.size() & 1) {
        s.push_back(s.back() != 'Z' ? 'Z' : 'Y');
    }
    return s;
}

string playfairCipher(string s, string key, int x) {
    vector<vector<char>> matrix = generatePlayfairMatrix(key);
    string digrams = generateDigrams(s), playfair(digrams);
    unordered_map<char, int> indices;
    int dn = digrams.size();
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            indices[matrix[r][c]] = r * 5 + c;
        }
    }
    indices['J'] = indices['I'];
    for (int i = 0; i < dn; i += 2) {
        int i1 = indices[digrams[i]], i2 = indices[digrams[i + 1]];
        int r1 = i1 / 5, c1 = i1 % 5, r2 = i2 / 5, c2 = i2 % 5;
        if (r1 == r2) {
            playfair[i] = matrix[r1][(c1 + x) % 5];
            playfair[i + 1] = matrix[r2][(c2 + x) % 5];
        } else if (c1 == c2) {
            playfair[i] = matrix[(r1 + x) % 5][c1];
            playfair[i + 1] = matrix[(r2 + x) % 5][c2];
        } else {
            playfair[i] = matrix[r1][c2];
            playfair[i + 1] = matrix[r2][c1];
        }
    }
    printPlayfairCipher(matrix, digrams, playfair);
    return playfair;
}

string playfairEncrypt(string s, string key) {
    return playfairCipher(s, key, 1);
}

string playfairDecrypt(string s, string key) {
    return playfairCipher(s, key, 4);
}

int main() {
    string s, key;
    cout << "Enter string: "; cin >> s;
    cout << "Enter key: "; cin >> key;
    string encrypted = playfairEncrypt(s, key);
    cout << "Encrypted string: " << encrypted << "\n";
    string decrypted = playfairDecrypt(encrypted, key);
    cout << "Decrypted string: " << decrypted << "\n";
    return 0;
}