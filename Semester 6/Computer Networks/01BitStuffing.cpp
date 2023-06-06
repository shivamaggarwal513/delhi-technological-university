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

vector<int> bit_stuffing(vector<int>& data, int flag, int bit) {
    vector<int> stuffed;
    int count = 0;
    stuffed.push_back(flag);
    for (int& x: data) {
        count = x == 1 ? count + 1 : 0;
        if (count == bit) {
            stuffed.push_back(0);
            count = 0;
        }
        stuffed.push_back(x);
    }
    stuffed.push_back(flag);
    return stuffed;
}

int main() {
    vector<int> data = {0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1};
    cout << "Before stuffing: " << data << "\n";
    cout << "After stuffing: " << bit_stuffing(data, 0, 5) << "\n";
    return 0;
}