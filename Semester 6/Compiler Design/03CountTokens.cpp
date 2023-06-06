#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class LexicalAnalysis {
private:
    vector<string> keywords, operators, punctuations, delimiters;

    bool is_keyword(const string& token) const {
        return find(keywords.begin(), keywords.end(), token) != keywords.end();
    }

    bool is_operator(const string& token) const {
        return find(operators.begin(), operators.end(), token) != operators.end();
    }

    bool is_punctuation(const string& token) const {
        return find(punctuations.begin(), punctuations.end(), token) != punctuations.end();
    }

    bool is_delimeter(const string& token) const {
        return find(delimiters.begin(), delimiters.end(), token) != delimiters.end();
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

    void print_token(const string& token, int& count) {
        if (token.empty()) {
            return;
        }
        cout << ++count << ". " << token << "\t: ";
        if (is_keyword(token)) {
            cout << "Keyword";
        } else if (is_operator(token)) {
            cout << "Operator";
        } else if (is_punctuation(token)) {
            cout << "Punctuation";
        } else if (is_number(token)) {
            cout << "Number";
        } else {
            cout << "Identifier";
        }
        cout << "\n";
    }

public:
    LexicalAnalysis() {
        keywords = {"auto", "break", "case", "char", "const", "continue", "default", "do",
                    "double", "else", "enum", "extern", "float", "for", "goto", "if",
                    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
                    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
        operators = {"+", "-", "*", "/", "%", "=", "<", ">", "<=", ">=", "==", "!="};
        punctuations = {"(", ")", "{", "}", "[", "]", ";", ","};
        delimiters = {" ", "\n", "\t"};
    }

    int count_tokens(const string& code) {
        int n = code.size(), count = 0;
        string token = "", c;
        for (int i = 0; i < n; i++) {
            c = string(1, code[i]);
            if (is_punctuation(c)) {
                print_token(token, count);
                print_token(c, count);
                token.clear();
            } else if (is_operator(c)) {
                print_token(token, count);
                token = code[i];
            } else if (is_delimeter(c)) {
                print_token(token, count);
                token.clear();
            } else {
                token.push_back(code[i]);
            }
        }
        return count;
    }
};

int main() {
    LexicalAnalysis t;
    string code;
    getline(cin, code);
    cout << "\nToken count: " << t.count_tokens(code) << "\n";
    return 0;
}

/*
int a = b + 1;
int main() { int a = 5; if (a > 0) { a = a + 1; } return 0; }
*/