#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

// {System, Effort, Time, Persons}
vector<float> constructive_cost(int kloc) {
    static vector<vector<float>> coeff = {{2.4, 1.05, 2.5, 0.38}, {3.0, 1.12, 2.5, 0.35}, {3.6, 1.20, 2.5, 0.32}};
    vector<float> result(4);
    result[0] = kloc <= 50 ? 0 : kloc <= 300 ? 1 : 2;
    result[1] = coeff[result[0]][0] * pow(kloc, coeff[result[0]][1]);
    result[2] = coeff[result[0]][2] * pow(result[1], coeff[result[0]][3]);
    result[3] = ceil(result[1] / result[2]);
    return result;
}

int main() {
    vector<string> system = {"Organic", "Semi-Detached", "Embedded"};
    int kloc;
    cout << "Enter number of lines of code in KLOC: ";
    cin >> kloc;
    vector<float> result = constructive_cost(kloc);
    cout << fixed << setprecision(2)
        << "System: " << system[result[0]] << "\n"
        << "Effort: " << result[1] << " Person Months\n"
        << "Time: " << result[2] << " Months\n"
        << "Persons: " << result[3] << " Persons\n";
    return 0;
}