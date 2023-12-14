#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

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

void generateKeys(long long& publicKey, long long& privateKey, long long& n) {
    long long p = 7907, q = 7919;
    // cout << "Enter two prime numbers (p and q): "; cin >> p >> q;
    n = p * q;
    long long phi = (p - 1) * (q - 1);
    for (publicKey = 2; publicKey < phi && gcd(publicKey, phi) != 1; publicKey++);
    for (long long k = 2; 1; k++) {
        long long d = (1 + k * phi) / publicKey;
        if ((d * publicKey) % phi == 1) {
            privateKey = d;
            break;
        }
    }
}

long long RSAEncrypt(long long m, long long publicKey, long long n) {
    return powerMod(m, publicKey, n);
}

long long RSADecrypt(long long m, long long privateKey, long long n) {
    return powerMod(m, privateKey, n);
}

int main() {
    long long message, publicKey, privateKey, n;
    generateKeys(publicKey, privateKey, n);
    cout << "Public key: (" << publicKey << ", " << n << ")\n";
    cout << "Private key: (" << privateKey << ", " << n << ")\n";
    cout << "Enter message: "; cin >> message;
    long long encrypted = RSAEncrypt(message, publicKey, n);
    long long decrypted = RSADecrypt(encrypted, privateKey, n);
    cout << "Encrypted message: " << encrypted << "\n";
    cout << "Decrypted message: " << decrypted << "\n";
    return 0;
}