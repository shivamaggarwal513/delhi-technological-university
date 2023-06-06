#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
        for (int s: curr) {
            for (int x: transition[{s}][input]) {
                result.insert(x);
            }
        }
        return result;
    }

public:
    FiniteAutomata() : nstates(0), ninputs(0), nfinal(0) {}

    FiniteAutomata to_dfa() {
        FiniteAutomata dfa;
        set<set<int>> visited;
        set<int> curr, nexts;
        queue<set<int>> q;
        bool isdead = false;
        q.push({0});
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (visited.find(curr) != visited.end()) {
                continue;
            }
            visited.insert(curr);
            dfa.transition[curr] = vector<set<int>>(ninputs);
            for (int i = 0; i < ninputs; i++) {
                nexts = next_state(curr, i);
                if (!nexts.empty()) {
                    dfa.transition[curr][i] = nexts;
                    q.push(nexts);
                } else {
                    dfa.transition[curr][i] = {nstates};
                    isdead = true;
                }
            }
        }
        // check if dead state is needed
        if (isdead) {
            dfa.transition[{nstates}] = vector<set<int>>(ninputs, {nstates});
        }
        // mark final states
        for (auto it = dfa.transition.begin(); it != dfa.transition.end(); it++) {
            for (int s: it->first) {
                if (is_final({s})) {
                    dfa.fstates.insert(it->first);
                    break;
                }
            }
        }
        dfa.nstates = dfa.transition.size();
        dfa.ninputs = ninputs;
        dfa.nfinal = dfa.fstates.size();
        return dfa;
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
    FiniteAutomata nfa;
    cin >> nfa;
    cout << "\nNFA\n" << nfa << "\n";
    FiniteAutomata dfa = nfa.to_dfa();
    cout << "DFA\n" << dfa << "\n";
    return 0;
}

/*
3 2
1 0 1 1
2 1 2 1 1
1 2 2 1 2
1 2

2 2
2 0 1 1 1
0 2 0 1
1 1

3 2
2 0 1 1 0
0 1 2
0 0
1 2

3 2
1 0 2 0 1
0 1 2
0 0
1 2

3 2
1 0 2 1 2
2 1 2 1 2
2 0 1 1 1
1 2

3 2
2 1 2 0
0 0
2 1 2 1 2
1 1

2 2
1 1 0
1 1 1 1
1 1

2 2
2 0 1 1 0
0 0
1 1

3 2
1 1 1 1
1 2 0
1 2 1 2
1 2

3 2
2 0 1 1 0
1 2 1 2
0 0
1 2

4 2
2 0 1 1 0
1 2 1 2
1 3 1 3
0 0
1 3
*/