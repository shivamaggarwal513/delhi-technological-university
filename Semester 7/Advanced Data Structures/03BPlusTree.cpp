#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class BPlusTreeNode {
private:
    bool leaf;
    vector<int> keys;
    vector<BPlusTreeNode*> children;

    bool isFull(int k) {
        return keys.size() == k;
    }

    bool isOverflow(int k) {
        return keys.size() == k + 1;
    }

public:
    BPlusTreeNode(bool leaf = true) : leaf(leaf) {}

    ~BPlusTreeNode() {
        for (BPlusTreeNode* child : children) {
            delete child;
        }
    }

    friend class BPlusTree;
};

class BPlusTree {
private:
    int k;
    BPlusTreeNode* root;

    int upperBound(BPlusTreeNode* curr, int x) {
        return upper_bound(curr->keys.begin(), curr->keys.end(), x) - curr->keys.begin();
    }

    void shiftLevelUp(BPlusTreeNode* parent, BPlusTreeNode* child) {
        if (!parent) {
            root = parent = new BPlusTreeNode(false);
            parent->children.push_back(child);
        }
        int mid = (k + 1) / 2, x = child->keys[mid], i = upperBound(parent, x);
        BPlusTreeNode* newChild = new BPlusTreeNode(child->leaf);
        parent->keys.insert(parent->keys.begin() + i, x);
        parent->children.insert(parent->children.begin() + i + 1, newChild);
        for (int i = mid + !child->leaf; i <= k; i++) {
            newChild->keys.push_back(child->keys[i]);
        }
        child->keys.resize(mid);
        if (!child->leaf) {
            for (int i = mid + 1; i <= k + 1; i++) {
                newChild->children.push_back(child->children[i]);
            }
            child->children.resize(mid + 1);
        }
    }

    BPlusTreeNode* search(BPlusTreeNode* curr, int x) {
        if (!curr) {
            return nullptr;
        }
        int i = upperBound(curr, x);
        if (curr->leaf) {
            return i != 0 && curr->keys[i - 1] == x ? curr : nullptr;
        }
        return search(curr->children[i], x);
    }
    
    void deleteNode(BPlusTreeNode* curr) {
        curr->children.clear();
        delete curr;
    }

    void insert(BPlusTreeNode* parent, BPlusTreeNode* child, int x) {
        int i = upperBound(child, x);
        if (child->leaf) {
            child->keys.insert(child->keys.begin() + i, x);
        }
        else {
            insert(child, child->children[i], x);
        }
        if (child->isOverflow(k)) {
            shiftLevelUp(parent, child);
        }
    }

    void fillInorder(BPlusTreeNode* curr, vector<int>& inorder) {
        if (!curr) {
            return;
        }
        if (curr->leaf) {
            inorder.insert(inorder.end(), curr->keys.begin(), curr->keys.end());
        }
        for (BPlusTreeNode* child : curr->children) {
            fillInorder(child, inorder);
        }
    }

    void fillInorderString(BPlusTreeNode* curr, string& inorder) {
        if (!curr) {
            return;
        }
        int kn = curr->keys.size();
        inorder.push_back('(');
        for (int i = 0; i < kn; i++) {
            if (!curr->leaf) {
                fillInorderString(curr->children[i], inorder);
                inorder.push_back(',');
            }
            inorder += to_string(curr->keys[i]) + ",";
        }
        if (!curr->leaf) {
            fillInorderString(curr->children[kn], inorder);
            inorder.push_back(',');
        }
        inorder.back() = ')';
    }

public:
    BPlusTree(int k) : k(k), root(nullptr) {}

    bool search(int x) {
        return search(root, x) != nullptr;
    }

    void insert(int x) {
        if (!root) {
            root = new BPlusTreeNode();
            root->keys.push_back(x);
            return;
        }
        insert(nullptr, root, x);
    }

    vector<int> traverse() {
        vector<int> result;
        fillInorder(root, result);
        return result;
    }

    friend ostream& operator<<(ostream& os, BPlusTree& tree);

    ~BPlusTree() {
        delete root;
    }
};

ostream& operator<<(ostream& os, BPlusTree& tree) {
    string s;
    tree.fillInorderString(tree.root, s);
    os << s;
    return os;
}

int main() {
    BPlusTree tree(3);
    for (int i = 1; i <= 10; i++) {
        tree.insert(i);
        cout << "Inserted " << i << ": " << tree << "\n";
    }
    vector<int> result = tree.traverse();
    cout << "Traverse: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\nTree: " << tree << "\n";
    // for (int i = 10; i >= 1; i--) {
    //    tree.remove(i);
    //    cout << "Removed " << i << ": " << tree << "\n";
    // }
    return 0;
}