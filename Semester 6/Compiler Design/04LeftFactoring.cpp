#include <iostream>
#include <string>
#include <map>
#include <set>
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

    Grammar left_factor() {
        int c;
        Grammar fact(*this);
        for (auto& p: fact.productions) {
            for (auto it = p.second.begin(); it != p.second.end(); it++) {
                for (auto jt = next(it); jt != p.second.end(); jt++) {
                    for (c = 0; c < it->size() && c < jt->size() && (*it)[c] == (*jt)[c]; c++);
                    if (c == 0) {
                        continue;
                    }
                    string common = it->substr(0, c);
                    char var = *fact.available.begin();
                    fact.available.erase(fact.available.begin());
                    fact.nvar++; fact.variables.insert(var);
                    fact.nprod += fact.productions.find(var) == fact.productions.end();
                    fact.productions[p.first].insert(common + var);
                    fact.productions[var].insert(it->substr(c));
                    fact.productions[var].insert(jt->substr(c));
                    fact.productions[p.first].erase(it);
                    fact.productions[p.first].erase(jt);
                    return fact.left_factor();
                }
            }
        }
        return fact;
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
    cout << "Grammar after left factoring\n" << g.left_factor() << "\n";
    return 0;
}

/*
ε

2 S E
5 a b e i t
S
2
S 3 iEtS iEtSeS a
E 1 b

2 A B
2 a c
A
1
A 3 aAB aBc aAc

1 S
2 a b
S
1
S 4 bSSaaS bSSaSb bSb a

1 S
2 a b
S
1
S 4 aSSbS aSaSb abb b

1 S
4 a b c d
S
1
S 4 a ab abc abcd

3 S A B
4 a b c d
S
3
S 2 aAd aB
A 2 a ab
B 2 ccd ddc
*/