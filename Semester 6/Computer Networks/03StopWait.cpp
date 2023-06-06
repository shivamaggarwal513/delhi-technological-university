#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

bool is_packet_lost(double p) {
    double r = (double)rand() / RAND_MAX;
    return r < p;
}

int main() {
    srand(time(0));
    int sender = 0;
    int receiver = 0;
    double prob = 0.2;
    for (int i = 0; i < 10; i++) {
        cout << "Sender   : Sending packet " << sender << "\n";
        Sleep(rand() % 10);
        if (is_packet_lost(prob)) {
            cout << "Sender   : Packet " << sender << " lost\n";
            continue;
        }
        cout << "Receiver : Received packet " << sender << "\n";
        Sleep(rand() % 10);
        if (is_packet_lost(prob)) {
            cout << "Receiver : Acknowledgment lost\n";
            continue;
        }
        cout << "Sender   : Received acknowledgment " << sender << "\n";
        receiver = ++sender;
    }
    return 0;
}