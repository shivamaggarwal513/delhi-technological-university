#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int binToDec(string s) {
    int result = 0;
    for (int i = s.size() - 1, p = 1; i >= 0; i--, p <<= 1) {
        result += (s[i] - '0') * p;
    }
    return result;
}

string decToBin(int n) {
    string result;
    while (n) {
        result.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(result.begin(), result.end());
    return result;
}

string charToBin(string message) {
    string result;
    for (char ch: message) {
        string x = decToBin(ch);
        result += string(8 - x.size(), '0') + x;
    }
    return result;
}

string binToHex(string s) {
    string result;
    for (int i = 0; i < s.size(); i += 4) {
        int x = binToDec(s.substr(i, 4));
        result.push_back(x + (x < 10 ? '0' : 'A' - 10));
    }
    return result;
}

string hexToBin(string s) {
    string result;
    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - (isdigit(s[i]) ? '0' : 'A' - 10);
        string x = decToBin(d);
        result += string(4 - x.size(), '0') + x;
    }
    return result;
}

string leftCircularShift(string s, int shift) {
    shift %= s.size();
    return s.substr(shift) + s.substr(0, shift);
}

string binAND(string s, string t) {
    int sn = s.size();
    string result(sn, 0);
    for (int i = 0; i < sn; i++) {
        result[i] = s[i] == '1' && t[i] == '1' ? '1' : '0';
    }
    return result;
}

string binOR(string s, string t) {
    int sn = s.size();
    string result(sn, 0);
    for (int i = 0; i < sn; i++) {
        result[i] = s[i] == '1' || t[i] == '1' ? '1' : '0';
    }
    return result;
}

string binNOT(string s) {
    int sn = s.size();
    string result(sn, 0);
    for (int i = 0; i < sn; i++) {
        result[i] = s[i] == '1' ? '0' : '1';
    }
    return result;
}

string binXOR(string s, string t) {
    int sn = s.size();
    string result(sn, 0);
    for (int i = 0; i < sn; i++) {
        result[i] = s[i] == t[i] ? '0' : '1';
    }
    return result;
}

string binAdd(string s, string t) {
    int sn = s.size(), sum = 0;
    string result(sn, 0);
    for (int i = sn - 1; i >= 0; i--) {
        sum += (s[i] - '0') + (t[i] - '0');
        result[i] = (sum & 1) + '0';
        sum >>= 1;
    }
    return result;
}

string preProcess(string message) {
    int ml = message.size() * 8;
    string mlBin = decToBin(ml);
    message = charToBin(message);
    if (ml % 8 == 0) {
        message += "10000000";
    }
    int k = (448 - (message.size() % 512) + 512) % 512;
    return message + string(k + (64 - mlBin.size()), '0') + mlBin;
}

string SHA1(string message) {
    int ml = message.size() * 8;
    string s = preProcess(message);
    vector<string> h{hexToBin("67452301"), hexToBin("EFCDAB89"), hexToBin("98BADCFE"), hexToBin("10325476"), hexToBin("C3D2E1F0")};
    for (int chunkStart = 0; chunkStart < s.size(); chunkStart += 512) {
        vector<string> w(80);
        for (int i = 0; i < 80; i++) {
            if (i < 16) {
                w[i] = s.substr(chunkStart + i * 32, 32);
            } else {
                w[i] = leftCircularShift(binXOR(binXOR(binXOR(w[i - 3], w[i - 8]), w[i - 14]), w[i - 16]), 1);
            }
        }
        string a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f, k;
        for (int i = 0; i < 80; i++) {
            if (i < 20) {
                f = binOR(binAND(b, c), binAND(binNOT(b), d));
                k = hexToBin("5A827999");
            } else if (i < 40) {
                f = binXOR(binXOR(b, c), d);
                k = hexToBin("6ED9EBA1");
            } else if (i < 60) {
                f = binOR(binOR(binAND(b, c), binAND(b, d)), binAND(c, d));
                k = hexToBin("8F1BBCDC");
            } else {
                f = binXOR(binXOR(b, c), d);
                k = hexToBin("CA62C1D6");
            }
            string temp = binAdd(binAdd(binAdd(binAdd(leftCircularShift(a, 5), f), e), k), w[i]);
            e = d;
            d = c;
            c = leftCircularShift(b, 30);
            b = a;
            a = temp;
        }
        h[0] = binAdd(h[0], a);
        h[1] = binAdd(h[1], b);
        h[2] = binAdd(h[2], c);
        h[3] = binAdd(h[3], d);
        h[4] = binAdd(h[4], e);
    }
    h[0] = leftCircularShift(h[0], 128);
    h[1] = leftCircularShift(h[1], 96);
    h[2] = leftCircularShift(h[2], 64);
    h[3] = leftCircularShift(h[3], 32);
    return binToHex(h[0] + h[1] + h[2] + h[3] + h[4]);
}

int main() {
    string message;
    cout << "Enter message: "; cin >> message;
    cout << "SHA1: " << SHA1(message);
    return 0;
}