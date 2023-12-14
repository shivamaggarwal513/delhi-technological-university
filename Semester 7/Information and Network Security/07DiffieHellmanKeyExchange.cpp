#include <iostream>
using namespace std;

long long powerMod(long long x, long long n, long long mod) {
    long long result = 1, p = x;
    while (n) {
        if (n & 1) {
            result = (result * p) % mod;
        }
        p = (p * p) % mod;
        n >>= 1;
    }
    return result;
}

int main() {
    long long prime, base, privateA, privateB;
    cout << "Enter a prime number: "; cin >> prime;
    cout << "Enter a base: "; cin >> base;
    cout << "Enter Alice's private key: "; cin >> privateA;
    cout << "Enter Bob's private key: "; cin >> privateB;
    long long publicA = powerMod(base, privateA, prime);
    long long publicB = powerMod(base, privateB, prime);
    long long sharedKeyA = powerMod(publicB, privateA, prime);
    long long sharedKeyB = powerMod(publicA, privateB, prime);
    if (sharedKeyA == sharedKeyB) {
        cout << "Key exchange successful\n";
        cout << "Shared Key: " << sharedKeyA << "\n";
    } else {
        cout << "Key exchange failed\n";
    }
    return 0;
}