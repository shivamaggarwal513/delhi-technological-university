#include <iostream>
#include <string>
using namespace std;

string encrypt(string& s, int k) {
    int n = s.size();
    string encrypted(s);
    for (int i = 0; i < n; i++) {
        if (islower(s[i])) {
            encrypted[i] = (s[i] + k - 'a' + 26) % 26 + 'a';
        } else {
            encrypted[i] = (s[i] + k - 'A' + 26) % 26 + 'A';
        }
    }
    return encrypted;
}

string decrypt(string& s, int k) {
    int n = s.size();
    string decrypted(s);
    for (int i = 0; i < n; i++) {
        if (islower(s[i])) {
            decrypted[i] = (s[i] - k - 'a' + 26) % 26 + 'a';
        } else {
            decrypted[i] = (s[i] - k - 'A' + 26) % 26 + 'A';
        }
    }
    return decrypted;
}

int main() {
    int k;
    string s;
    cout << "Enter key: "; cin >> k;
    cout << "Enter string: "; cin >> s;
    string encrypted = encrypt(s, k);
    string decrypted = decrypt(encrypted, k);
    cout << "Encrypted string: " << encrypted << "\n";
    cout << "Decrypted string: " << decrypted << "\n";
    return 0;
}