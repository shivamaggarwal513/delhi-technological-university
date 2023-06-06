#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
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
        os << (nf ? "," : (nf = true, "")) << (x ? x : (char)0xEE);
    }
    os << "}";
    return os;
}

// output overload for string set
ostream& operator<<(ostream& os, const set<string>& s) {
    bool nf = false;
    for (const string& x : s) {
        os << (nf ? " | " : (nf = true, "")) << (!x.empty() ? x : string(1, (char)0xEE));
    }
    return os;
}

// output overload for map
ostream& operator<<(ostream& os, const map<char, set<char>>& m) {
    for (const auto& p : m) {
        os << "   " << p.first << ": " << p.second << "\n";
    }
    return os;
}

class Grammar {
private:
    char start;
    int nvar, nterm, nprod;
    set<char> variables, terminals, available;
    map<char, set<string>> productions;
    map<char, set<char>> first, follow;
    map<char, vector<vector<pair<char, string>>>> parsing_table;

    bool is_variable(char ch) {
        return variables.find(ch) != variables.end();
    }

    bool is_terminal(char ch) {
        return terminals.find(ch) != terminals.end();
    }

    set<char> FIRST(char ch) {
        if (first.find(ch) != first.end()) {
            return first[ch];
        }
        set<char> result;
        for (auto& s : productions[ch]) {
            if (s.empty()) {
                result.insert('\0');
            }
            else {
                set<char> x = FIRST(s);
                result.insert(x.begin(), x.end());
            }
        }
        return first[ch] = result;
    }

    set<char> FIRST(string s) {
        int n = s.size();
        if (n == 0) {
            return { '\0' };
        }
        set<char> result;
        for (int i = 0; i < n; i++) {
            if (is_terminal(s[i])) {
                result.insert(s[i]);
                break;
            }
            set<char> x = FIRST(s[i]);
            if (i != n - 1 && x.find('\0') != x.end()) {
                x.erase('\0');
                result.insert(x.begin(), x.end());
            }
            else {
                result.insert(x.begin(), x.end());
                break;
            }
        }
        return result;
    }

    set<char> FOLLOW(char ch) {
        if (follow.find(ch) != follow.end()) {
            return follow[ch];
        }
        set<char> result;
        if (ch == start) {
            result.insert('$');
        }
        for (auto& p : productions) {
            for (auto& s : p.second) {
                int n = s.size();
                for (int i = 0; i < n; i++) {
                    if (s[i] == ch) {
                        if (i == n - 1) {
                            if (s[i] != p.first) {
                                set<char> x = FOLLOW(p.first);
                                result.insert(x.begin(), x.end());
                            }
                        }
                        else {
                            set<char> x = FIRST(s.substr(i + 1));
                            if (x.find('\0') != x.end() && s[i] != p.first) {
                                x.erase('\0');
                                set<char> y = FOLLOW(p.first);
                                x.insert(y.begin(), y.end());
                            }
                            result.insert(x.begin(), x.end());
                        }
                    }
                }
            }
        }
        return follow[ch] = result;
    }

    string pair_to_string(pair<char, string> p) {
        return string(1, p.first) + " -> " + (!p.second.empty() ? p.second : string(1, 0xEE));
    }

    string vector_to_string(vector<string> v) {
        string s = "{";
        bool nf = false;
        for (const string& x : v) {
            s += (nf ? "," : (nf = true, "")) + x;
        }
        s += "}";
        return s;
    }

    string vector_to_string(vector<pair<char, string>> v) {
        string s = "{";
        bool nf = false;
        for (const auto& x : v) {
            s += (nf ? "," : (nf = true, "")) + pair_to_string(x);
        }
        s += "}";
        return s;
    }

    string stack_to_string(stack<char> stk) {
        string s = "{";
        bool nf = false;
        while (!stk.empty()) {
            s += (nf ? "," : (nf = true, "")) + string(1, stk.top());
            stk.pop();
        }
        s += nf ? "," : "";
        s += "$}";
        return s;
    }

    void print(string s) {
        cout << setw(20) << left << s;
    }

    void print_LL1_parsing_table() {
        cout << "LL(1) Parsing Table\n\n\t";
        for (char t : terminals) {
            cout << setw(20) << left << t;
        }
        print("$");
        cout << "\n";
        for (auto& p : parsing_table) {
            cout << p.first << "\t";
            for (auto& cell : p.second) {
                print(vector_to_string(cell));
            }
            cout << "\n";
        }
    }

    void print_LL1_output(vector<vector<string>>& v) {
        cout << "\nLL(1) Parsing\n\n";
        print("Input"); print("Stack"); print("Output");
        cout << "\n" << string(46, '-') << "\n";
        for (auto& r : v) {
            for (auto& c : r) {
                print(c);
            }
            cout << "\n";
        }
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

    map<char, set<char>> getFIRST() {
        for (auto& p : productions) {
            FIRST(p.first);
        }
        return first;
    }

    map<char, set<char>> getFOLLOW() {
        for (auto& p : productions) {
            FOLLOW(p.first);
        }
        return follow;
    }

    bool make_LL1_parsing_table() {
        bool is_LL1 = true;
        for (auto& p : productions) {
            parsing_table[p.first].resize(terminals.size() + 1);
            for (auto& s : p.second) {
                set<char> x = FIRST(s);
                if (x.find('\0') != x.end()) {
                    x.erase('\0');
                    set<char> y = FOLLOW(p.first);
                    x.insert(y.begin(), y.end());
                }
                for (char t : x) {
                    int ti = distance(terminals.begin(), terminals.find(t));
                    parsing_table[p.first][ti].push_back({ p.first, s });
                    if (parsing_table[p.first][ti].size() > 1) {
                        is_LL1 = false;
                    }
                }
            }
        }
        return is_LL1;
    }

    bool LL1_parser(string s) {
        bool is_LL1 = make_LL1_parsing_table(), parsed = true;
        print_LL1_parsing_table();
        if (!is_LL1) {
            return false;
        }
        int n = s.size(), look_ahead = 0;
        vector<vector<string>> output;
        stack<char> stk;
        stk.push(start);
        while (!stk.empty()) {
            char curr = stk.top();
            if (is_variable(curr)) {
                if (look_ahead < n) {
                    int d = distance(terminals.begin(), terminals.find(s[look_ahead]));
                    output.push_back({ s.substr(look_ahead) + "$", stack_to_string(stk), vector_to_string(parsing_table[curr][d]) });
                    if (!parsing_table[curr][d].empty()) {
                        stk.pop();
                        for (int i = parsing_table[curr][d][0].second.size() - 1; i >= 0; i--) {
                            stk.push(parsing_table[curr][d][0].second[i]);
                        }
                    }
                    else {
                        parsed = false;
                        break;
                    }
                }
                else {
                    if (productions[curr].find("") != productions[curr].end()) {
                        output.push_back({ "$", stack_to_string(stk), pair_to_string({curr, ""}) });
                        stk.pop();
                    }
                    else {
                        parsed = false;
                        break;
                    }
                }
            }
            else {
                output.push_back({ s.substr(look_ahead) + "$", stack_to_string(stk), "match " + string(1, curr) });
                if (look_ahead < n && s[look_ahead++] == curr) {
                    stk.pop();
                }
                else {
                    parsed = false;
                    break;
                }
            }
        }
        output.push_back({ s.substr(look_ahead) + "$", stack_to_string(stk), ""});
        print_LL1_output(output);
        return parsed;
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
    cout << "\nGrammar\n" << g << "\n";
    map<char, set<char>> first = g.getFIRST();
    cout << "FIRST:\n" << first << "\n";
    map<char, set<char>> follow = g.getFOLLOW();
    cout << "FOLLOW:\n" << follow << "\n";
    bool result = g.LL1_parser(s);
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

(i+*i)
*/