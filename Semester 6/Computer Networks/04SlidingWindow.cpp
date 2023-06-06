#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

bool is_packet_lost(double p) {
    double r = (double)rand() / RAND_MAX;
    return r < p;
}

int main() {
    srand(time(0));
    int frames, window, ack = -1, window_end;
    double prob = 0.3;
    cout << "Number of frames: "; cin >> frames;
    cout << "Window size: "; cin >> window;
    while (ack < frames - 1) {
        window_end = min(ack + window + 1, frames);
        cout << "\nSending window: ";
        for (int i = ack + 1; i < window_end; i++) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i = ack + 1; i < window_end; i++) {
            if ((ack == i - 1) && !is_packet_lost(prob)) {
                cout << "Acknowledgment: " << ++ack << "\n";
            }
        }
        if (ack != window_end - 1) {
            cout << "Frame " << ack + 1 << " lost\n";
        }
    }
    return 0;
}