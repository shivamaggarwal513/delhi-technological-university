#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string vigenereEncrypt(string s, string key) {
    int n = s.size(), kn = key.size();
    string encrypted(s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    for (int i = 0; i < n; i++) {
        encrypted[i] = 'A' + (s[i] + key[i % kn] - 2 * 'A') % 26;
    }
    return encrypted;
}

string vigenereDecrypt(string s, string key) {
    int n = s.size(), kn = key.size();
    string decrypted(s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    for (int i = 0; i < n; i++) {
        decrypted[i] = 'A' + (s[i] - key[i % kn] + 26) % 26;
    }
    return decrypted;
}

int main() {
    string s, key;
    cout << "Enter string: "; cin >> s;
    cout << "Enter key: "; cin >> key;
    string encrypted = vigenereEncrypt(s, key);
    string decrypted = vigenereDecrypt(encrypted, key);
    cout << "Encrypted string: " << encrypted << "\n";
    cout << "Decrypted string: " << decrypted << "\n";
    return 0;
}