#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

// input overload for char set
istream& operator>>(istream& is, set<char>& s) {
    int n;
    char x;
    is >> n;
    while (n--) {
        is >> x;
        s.insert(x);
    }
    return is;
}

// input overload for string set
istream& operator>>(istream& is, set<string>& s) {
    int n;
    string x;
    is >> n;
    while (n--) {
        is >> x;
        s.insert(x != "?" ? x :"");
    }
    return is;
}

// output overload for string
ostream& operator<<(ostream& os, const string& s) {
    if (s.empty()) {
        os << (char)0xEE;
    } else {
        for (const char& c: s) {
            os << c;
        }
    }
    return os;
}

// output overload for char set
ostream& operator<<(ostream& os, const set<char>& s) {
    bool nf = false;
    os << "{";
    for (const char& x: s) {
        os << (nf ? "," : (nf = true, "")) << x;
    }
    os << "}";
    return os;
}

// output overload for string set
ostream& operator<<(ostream& os, const set<string>& s) {
    bool nf = false;
    for (const string& x: s) {
        os << (nf ? " | " : (nf = true, "")) << x;
    }
    return os;
}

class Grammar {
private:
    char start;
    int nvar, nterm, nprod;
    set<char> variables, terminals, available;
    map<char, set<string>> productions;
    
public:
    Grammar() : start(0), nvar(0), nterm(0), nprod(0) {
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            available.insert(ch);
        }
    }

    Grammar(const Grammar& g) {
        start = g.start;
        nvar = g.nvar;
        nterm = g.nterm;
        nprod = g.nprod;
        variables = g.variables;
        terminals = g.terminals;
        available = g.available;
        productions = g.productions;
    }

    Grammar remove_left_recursion() {
        Grammar rec(*this);
        for (auto& p: rec.productions) {
            for (string r: p.second) {
                if (r.front() == p.first) {
                    set<string> x = p.second;
                    p.second.clear();
                    char var = *rec.available.begin();
                    rec.available.erase(rec.available.begin());
                    rec.nvar++; rec.variables.insert(var);
                    rec.nprod += rec.productions.find(var) == rec.productions.end();
                    rec.productions[var].insert("");
                    for (string y: x) {
                        if (y.front() == p.first) {
                            rec.productions[var].insert(y.substr(1) + var);
                        } else {
                            rec.productions[p.first].insert(y + var);
                        }
                    }
                    return rec.remove_left_recursion();
                }
            }
        }
        return rec;
    }

    friend istream& operator>>(istream& is, Grammar& g);
    friend ostream& operator<<(ostream& os, const Grammar& g);
};

// input overload for grammar
istream& operator>>(istream& is, Grammar& g) {
    char ch;
    is >> g.variables >> g.terminals;
    g.nvar = g.variables.size();
    g.nterm = g.terminals.size();
    for (const char& ch: g.variables) {
        g.available.erase(ch);
    }
    is >> g.start >> g.nprod;
    for (int i = 0; i < g.nprod; i++) {
        is >> ch;
        is >> g.productions[ch];
    }
    return is;
}

// output overload for grammar
ostream& operator<<(ostream& os, const Grammar& g) {
    os << "V: " << g.variables << "\n";
    os << "T: " << g.terminals << "\n";
    os << "S: " << g.start << "\n";
    os << "P: \n";
    for (auto& p: g.productions) {
        os << "   " << p.first << " -> " << p.second << "\n";
    }
    return os;
}

int main() {
    Grammar g;
    cin >> g;
    cout << "\nGrammar\n" << g << "\n";
    cout << "Removing left recursion\n" << g.remove_left_recursion() << "\n";
    return 0;
}

/*
ε

1 S
4 a b c d
S
1
S 4 Sa Sb c d

3 E T F
2 + *
E
3
E 2 E+T T
T 2 T*F F
F 2 E ?
*/