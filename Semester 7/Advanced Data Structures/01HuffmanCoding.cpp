#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class TreeNode {
public:
    char ch;
    int val;
    TreeNode* left, *right;

    TreeNode(char ch = 0, int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : ch(ch), val(val), left(left), right(right) {}
    
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class HuffmanCoding {
private:
    string s;
    TreeNode* root;
    unordered_map<char, string> codes;

    void fillHuffmanCodes(TreeNode* root, string code) {
        if (!root->left && !root->right) {
            codes[root->ch] = code;
            return;
        }
        if (root->left) {
            fillHuffmanCodes(root->left, code + "0");
        }
        if (root->right) {
            fillHuffmanCodes(root->right, code + "1");
        }
    }

public:
    HuffmanCoding(string s) : s(s), root(nullptr) {}

    TreeNode* buildHuffmanTree() {
        if (root) {
            return root;
        }
        unordered_map<char, int> freq;
        for (char ch: s) {
            freq[ch]++;
        }
        auto comp = [](TreeNode* r1, TreeNode* r2) { return r1->val > r2->val; };
        priority_queue<TreeNode*, vector<TreeNode*>, decltype(comp)> pq(comp);
        for (auto& p: freq) {
            pq.push(new TreeNode(p.first, p.second));
        }
        while (pq.size() > 1) {
            TreeNode* left = pq.top(); pq.pop();
            TreeNode* right = pq.top(); pq.pop();
            root = new TreeNode(0, left->val + right->val, left, right);
            pq.push(root);
        }
        return root;
    }

    unordered_map<char, string> getHuffmanCodes() {
        buildHuffmanTree();
        fillHuffmanCodes(root, "");
        return codes;
    }
    
    string encode() {
        getHuffmanCodes();
        string result;
        for (char ch: s) {
            result += codes[ch];
        }
        return result;
    }
};

int binToDec(string s) {
    int result = 0;
    for (int i = s.size() - 1, p = 1; i >= 0; i--, p <<= 1) {
        result += (s[i] - '0') * p;
    }
    return result;
}

string binToHex(string s) {
    string result;
    for (int i = 0; i < s.size(); i += 4) {
        int x = binToDec(s.substr(i, 4));
        result.push_back(x + (x < 10 ? '0' : 'A' - 10));
    }
    return result;
}

string binToStr(string s) {
    s = string(8 - s.size() % 8, '0') + s;
    int sn = s.size();
    string result;
    for (int i = 0; i < sn; i += 8) {
        result.push_back(binToDec(s.substr(i, 8)));
    }
    return result;
}

int main() {
    string s;
    cout << "Enter string: "; cin >> s;
    HuffmanCoding hc(s);
    unordered_map<char, string> codes = hc.getHuffmanCodes();
    cout << "Char\tCode\n";
    for (auto& p: codes) {
        cout << p.first << "\t" << p.second << "\n";
    }
    string encoded = hc.encode();
    cout << "Encoded string (hex): " << binToHex(encoded) << "\n";
    cout << "Encoded string (str): " << binToStr(encoded) << "\n";
    return 0;
}

/*
aaaaabbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffff
*/