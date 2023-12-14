#include <iostream>
#include <vector>
using namespace std;

string leftCircularShift(string s, int shift) {
    shift %= s.size();
    return s.substr(shift) + s.substr(0, shift);
}

string transpose(string s, vector<int>& permutation) {
    int pn = permutation.size();
    string t(pn, 0);
    for (int i = 0; i < pn; i++) {
        t[i] = s[permutation[i] - 1];
    }
    return t;
}

int main() {
    string key;
    vector<int> P10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    vector<int> P8 = {6, 3, 7, 4, 8, 5, 10, 9};

    cout << "Enter the 10-bit key (e.g., 1010000010): "; cin >> key;

    string p10key = transpose(key, P10);
    string left = leftCircularShift(p10key.substr(0, 5), 1);
    string right = leftCircularShift(p10key.substr(5), 1);

    string k1 = transpose(left + right, P8);

    left = leftCircularShift(left, 2);
    right = leftCircularShift(right, 2);

    string k2 = transpose(left + right, P8);

    cout << "Key K1: " << k1 << "\n";
    cout << "Key K2: " << k2 << "\n";

    return 0;
}