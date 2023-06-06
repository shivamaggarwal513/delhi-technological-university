#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const T& x: v) {
        os << x;
    }
    return os;
}

vector<int> calculate_crc(vector<int>& message, vector<int>& generator) {
    int mn = message.size(), gn = generator.size(), divn = mn + gn - 1, divi = gn;
    vector<int> dividend = message, remainder;
    for (int i = 0; i < gn; i++) {
        dividend.push_back(0);
        remainder.push_back(dividend[i]);
    }
    dividend.pop_back();
    while (divi < divn || remainder.front()) {
        for (int i = 0; i < gn; i++) {
            remainder[i] ^= generator[i];
        }
        while (divi < divn && !remainder.front()) {
            remainder.erase(remainder.begin());
            remainder.push_back(dividend[divi++]);
        }
    }
    for (int i = 1; i < gn; i++) {
        dividend[mn + i - 1] = remainder[i];
    }
    return dividend;
}

int main() {
    vector<int> message = {1, 0, 0, 1, 1, 0, 1};
    vector<int> generator = {1, 0, 1, 1};
    cout << "Message   : " << message << "\n";
    cout << "Generator : " << generator << "\n";
    cout << "CRC       : " << calculate_crc(message, generator) << "\n";
    return 0;
}

/*
          1010011
1011 | 1001101000
       1011
       ----------
       001010
         1011
       ----------
         0001100
            1011
       ----------
            01110
             1011
       ----------
             0101
*/