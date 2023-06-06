#include <iostream>
#include <string>
#include <set>
using namespace std;

// output overload for string set
ostream& operator<<(ostream& os, const set<string>& s) {
    for (const string& x: s) {
        os << x << " ";
    }
    return os;
}

class LexicalAnalysis {
private:
    set<string> _keywords, _operators, _punctuations, _delimiters;
    set<string> keywords, operators, punctuations, numbers, identifiers;

    bool is_keyword(const string& token) const {
        return _keywords.find(token) != _keywords.end();
    }

    bool is_operator(const string& token) const {
        return _operators.find(token) != _operators.end();
    }

    bool is_punctuation(const string& token) const {
        return _punctuations.find(token) != _punctuations.end();
    }

    bool is_delimeter(const string& token) const {
        return _delimiters.find(token) != _delimiters.end();
    }

    bool is_number(const string& token) const {
        int n = token.size(), decimal = 0;
        for (int i = 0; i < n; i++) {
            if ((token[i] < '0' || token[i] > '9') && (token[i] != '.' || decimal)) {
                return false;
            }
            decimal |= token[i] == '.';
        }
        return true;
    }

    void fill_token(const string& token) {
        if (token.empty()) {
            return;
        }
        if (is_keyword(token)) {
            keywords.insert(token);
        } else if (is_operator(token)) {
            operators.insert(token);
        } else if (is_punctuation(token)) {
            punctuations.insert(token);
        } else if (is_number(token)) {
            numbers.insert(token);
        } else {
            identifiers.insert(token);
        }
    }

public:
    LexicalAnalysis() {
        _keywords = {"auto", "break", "case", "char", "const", "continue", "default", "do",
                    "double", "else", "enum", "extern", "float", "for", "goto", "if",
                    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
                    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
        _operators = {"+", "-", "*", "/", "%", "=", "<", ">", "<=", ">=", "==", "!="};
        _punctuations = {"(", ")", "{", "}", "[", "]", ";", ","};
        _delimiters = {" ", "\n", "\t"};
    }

    void analyse(const string& code) {
        int n = code.size();
        string token = "", c;
        for (int i = 0; i < n; i++) {
            c = string(1, code[i]);
            if (is_punctuation(c)) {
                fill_token(token);
                fill_token(c);
                token.clear();
            } else if (is_operator(c)) {
                fill_token(token);
                token = code[i];
            } else if (is_delimeter(c)) {
                fill_token(token);
                token.clear();
            } else {
                token.push_back(code[i]);
            }
        }
        cout << "\nLexical Analysis\n";
        cout << "Keywords     : " << keywords << "\n";
        cout << "Operators    : " << operators << "\n";
        cout << "Punctuations : " << punctuations << "\n";
        cout << "Numbers      : " << numbers << "\n";
        cout << "Identifiers  : " << identifiers << "\n";
        keywords.clear(), operators.clear(), punctuations.clear(), numbers.clear(), identifiers.clear();
    }
};

int main() {
    LexicalAnalysis t;
    string code;
    getline(cin, code);
    t.analyse(code);
    return 0;
}

/*
int a = b + 1;
int main() { int a = 5; if (a > 0) { a = a + 1; } return 0; }
*/