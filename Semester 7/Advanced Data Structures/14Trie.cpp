#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class TrieNode {
private:
    bool word;
    vector<TrieNode*> children;

public:
    TrieNode(bool word = false) : word(word) {
        children.resize(26, nullptr);
    }

    ~TrieNode() {
        for (TrieNode* child: children) {
            delete child;
        }
    }

    friend class Trie;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(string& s) {
        TrieNode* curr = root;
        for (char ch: s) {
            if (!curr->children[ch - 'a']) {
                curr->children[ch - 'a'] = new TrieNode();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->word = true;
    }

    bool prefix(string& s) {
        TrieNode* curr = root;
        for (char ch: s) {
            if (!curr->children[ch - 'a']) {
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        return true;
    }
};

int main() {
    int t;
    string s, word;
    Trie trie;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> word) {
        trie.insert(word);
    }
    cin >> t;
    while (t--) {
        cin >> word;
        cout << (trie.prefix(word) ? "Prefix found" : "Prefix not found") << "\n";
    }
    return 0;
}