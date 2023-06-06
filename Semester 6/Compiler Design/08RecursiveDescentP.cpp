#include <iostream>
#include <iomanip>
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
        s.insert(x != "?" ? x : "");
    }
    return is;
}

// output overload for char set
ostream& operator<<(ostream& os, const set<char>& s) {
    bool nf = false;
    os << "{";
    for (const char& x : s) {
        os << (nf ? "," : (nf = true, "")) << x;
    }
    os << "}";
    return os;
}

// output overload for string set
ostream& operator<<(ostream& os, const set<string>& s) {
    bool nf = false;
    for (const string& x : s) {
        os << (nf ? " | " : (nf = true, "")) << (!x.empty() ? x : string(1, 0xEE));
    }
    return os;
}

class Grammar {
private:
    char start;
    int nvar, nterm, nprod;
    set<char> variables, terminals, available;
    map<char, set<string>> productions;

    bool is_variable(char ch) {
        return variables.find(ch) != variables.end();
    }

    bool is_terminal(char ch) {
        return terminals.find(ch) != terminals.end();
    }

    bool parse(string& s, int& i, char ch, vector<pair<string, pair<char, string>>>& table) {
        for (auto& x : productions[ch]) {
            int xi;
            for (xi = 0; xi < x.size(); xi++) {
                if (is_variable(x[xi])) {
                    if (xi == 0) {
                        table.push_back({s.substr(i), {ch, x}});
                    }
                    if (!parse(s, i, x[xi], table)) {
                        return false;
                    }
                }
                else if (s[i] == x[xi]) {
                    table.push_back({s.substr(i++), {ch, x}});
                }
                else {
                    break;
                }
            }
            if (!x.empty() && xi == x.size()) {
                return true;
            }
        }
        if (productions[ch].find("") != productions[ch].end()) {
            table.push_back({s.substr(i), {ch, ""}});
            return true;
        }
        return false;
    }

    void print(string s, string p) {
        cout << setw(20) << left << s << p << "\n";
    }

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

    void remove_left_recursion() {
        for (auto& p : productions) {
            for (string r : p.second) {
                if (!r.empty() && r.front() == p.first) {
                    set<string> x = p.second;
                    p.second.clear();
                    char var = *available.begin();
                    available.erase(available.begin());
                    nvar++; variables.insert(var);
                    nprod += productions.find(var) == productions.end();
                    productions[var].insert("");
                    for (string y : x) {
                        if (y.front() == p.first) {
                            productions[var].insert(y.substr(1) + var);
                        }
                        else {
                            productions[p.first].insert(y + var);
                        }
                    }
                    remove_left_recursion();
                    return;
                }
            }
        }
    }

    void left_factor() {
        int c;
        for (auto& p : productions) {
            for (auto it = p.second.begin(); it != p.second.end(); it++) {
                for (auto jt = next(it); jt != p.second.end(); jt++) {
                    for (c = 0; c < it->size() && c < jt->size() && (*it)[c] == (*jt)[c]; c++);
                    if (c == 0) {
                        continue;
                    }
                    string common = it->substr(0, c);
                    char var = *available.begin();
                    available.erase(available.begin());
                    nvar++; variables.insert(var);
                    nprod += productions.find(var) == productions.end();
                    productions[p.first].insert(common + var);
                    productions[var].insert(it->substr(c));
                    productions[var].insert(jt->substr(c));
                    productions[p.first].erase(it);
                    productions[p.first].erase(jt);
                    left_factor();
                    return;
                }
            }
        }
    }

    bool recursive_descent_parser(string s) {
        int i = 0;
        vector<pair<string, pair<char, string>>> table;
        bool result = parse(s, i, start, table);
        print("Input", "Action");
        print("--------------------", "----------");
        for (auto& row : table) {
            print(row.first, string(1, row.second.first) + " -> " + (!row.second.second.empty() ? row.second.second : string(1, 0xEE)));
        }
        print("--------------------", "----------");
        return result;
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
    for (const char& ch : g.variables) {
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
    for (auto& p : g.productions) {
        os << "   " << p.first << " -> " << p.second << "\n";
    }
    return os;
}

int main() {
    Grammar g;
    string s;
    cin >> g >> s;
    cout << "\nGrammar\n" << g << "\n";
    cout << "Removing left recursion...\n";
    g.remove_left_recursion();
    cout << "Left factoring...\n";
    g.left_factor();
    cout << "\nGrammar\n" << g;
    cout << "\nRecursive Descent Parsing\n\n";
    bool result = g.recursive_descent_parser(s);
    cout << "\n" << (result ? "Parsing successful" : "Error") << "\n\n";
    return 0;
}

/*
ε

3 E T F
5 + * ( ) i
E
3
E 2 E+T T
T 2 T*F F
F 2 (E) i

i+(i+i)*i

(i+i)*(i+i)
*/