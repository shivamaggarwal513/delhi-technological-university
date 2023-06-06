#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

// input overload for set
template <typename T>
istream& operator>>(istream& is, set<T>& s) {
    int n;
    T x;
    is >> n;
    while (n--) {
        is >> x;
        s.insert(x);
    }
    return is;
}

// output overload for set
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    bool nf = false;
    os << "{";
    for (const T& x: s) {
        os << (nf ? "," : (nf = true, "")) << x;
    }
    os << "}";
    return os;
}

class FiniteAutomata {
private:
    int nstates, ninputs, nfinal;
    map<set<int>, vector<set<int>>> transition;
    set<set<int>> fstates;

    bool is_final(const set<int> s) const {
        return fstates.find(s) != fstates.end();
    }

    set<int> next_state(const set<int>& curr, const int input) {
        set<int> result;
        for (const int& s: curr) {
            for (const int& x: transition[{s}][input]) {
                result.insert(x);
            }
        }
        return result;
    }

public:
    FiniteAutomata() : nstates(0), ninputs(0), nfinal(0) {}

    bool is_accepted(const string& s) {
        set<int> curr = {0};
        for (const char& ch: s) {
            curr = next_state(curr, ch - '0');
        }
        for (const int& s: curr) {
            if (is_final({s})) {
                return true;
            }
        }
        return false;
    }

    friend istream& operator>>(istream& is, FiniteAutomata& fa);
    friend ostream& operator<<(ostream& os, const FiniteAutomata& fa);
};

// input overload for finite automata
istream& operator>>(istream& is, FiniteAutomata& fa) {
    is >> fa.nstates >> fa.ninputs;
    for (int s = 0; s < fa.nstates; s++) {
        fa.transition[{s}] = vector<set<int>>(fa.ninputs);
        for (int i = 0; i < fa.ninputs; i++) {
            is >> fa.transition[{s}][i];
        }
    }
    is >> fa.nfinal;
    for (int fs = 0, x; fs < fa.nfinal; fs++) {
        is >> x;
        fa.fstates.insert({x});
    }
    return is;
}

// output overload for finite automata
ostream& operator<<(ostream& os, const FiniteAutomata& fa) {
    os << "\t ";
    for (int i = 0; i < fa.ninputs; i++) {
        os << i << "\t ";
    }
    os << "\n";
    for (auto it = fa.transition.begin(); it != fa.transition.end(); it++) {
        os << (fa.is_final(it->first) ? "*" : " ") << it->first << "\t";
        for (int i = 0; i < fa.ninputs; i++) {
            os << it->second[i] << "\t";
        }
        os << "\n";
    }
    return os;
}

int main() {
    int t;
    string s;
    FiniteAutomata dfa;
    cin >> dfa;
    cout << "\nDFA\n" << dfa << "\n";
    cin >> t;
    while (t--) {
        cin >> s;
        cout << (dfa.is_accepted(s) ? "Accepted" : "Not accepted") << "\n\n";
    }
    return 0;
}

/*
Starting with 0
3 2
1 1 1 2
1 1 1 1
1 2 1 2
1 1

Contains 010
4 2
1 1 1 0
1 1 1 2
1 3 1 0
1 3 1 3
1 3
*/