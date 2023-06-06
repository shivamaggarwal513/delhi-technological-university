#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<int>::iterator begin, vector<int>::iterator end) {
    bool nf = false;
    for (auto it = begin; it != end; it++) {
        cout << (nf ? "." : (nf = true, "")) << to_string(*it);
    }
}

void show_class_network_host(string address) {
    address.push_back('.');
    int octet = 0, network_end;
    char net_class;
    vector<int> octets;
    for (char& ch: address) {
        if (ch != '.') {
            octet = octet * 10 + (ch - '0');
        } else {
            octets.push_back(octet);
            octet = 0;
        }
    }
    net_class = octets[0] < 128 ? 'A' : octets[0] < 192 ? 'B' : octets[0] < 224 ? 'C' : octets[0] < 240 ? 'D' : 'E';
    network_end = min(4, (net_class - 'A') + 1);
    cout << "Class      : " << net_class << "\n";
    cout << "Network ID : ";
    print(octets.begin(), octets.begin() + network_end);
    cout << "\nHost ID    : ";
    print(octets.begin() + network_end, octets.end());
    cout << "\n";
}

int main() {
    string address;
    cout << "Enter IP address: ";
    cin >> address;
    show_class_network_host(address);
    return 0;
}