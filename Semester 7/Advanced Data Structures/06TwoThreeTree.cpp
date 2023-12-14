#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class BTreeNode {
protected:
    bool leaf;
    vector<int> keys;
    vector<BTreeNode*> children;

    bool isFull(int k) {
        return keys.size() == k;
    }

	bool isOverflow(int k) {
		return keys.size() == k + 1;
	}

public:
    BTreeNode(bool leaf = true) : leaf(leaf) {}

    ~BTreeNode() {
        for (BTreeNode* child: children) {
            delete child;
        }
    }

    friend class BTree;
};

class BTree {
protected:
    int k;
    BTreeNode* root;

    int lowerBound(BTreeNode* curr, int x) {
        return lower_bound(curr->keys.begin(), curr->keys.end(), x) - curr->keys.begin();
    }

    BTreeNode* search(BTreeNode* curr, int x) {
        if (!curr) {
            return nullptr;
        }
        int i = lowerBound(curr, x);
        if (i != curr->keys.size() && curr->keys[i] == x) {
            return curr;
        }
        return !curr->leaf ? search(curr->children[i], x) : nullptr;
    }

    void shiftLevelUp(BTreeNode* parent, BTreeNode* child) {
        if (!parent) {
            root = parent = new BTreeNode(false);
            parent->children.push_back(child);
        }
        int mid = (k + 1) / 2, x = child->keys[mid], i = lowerBound(parent, x);
        BTreeNode* newChild = new BTreeNode(child->leaf);
        parent->keys.insert(parent->keys.begin() + i, x);
        parent->children.insert(parent->children.begin() + i + 1, newChild);
        for (int i = mid + 1; i <= k; i++) {
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

    void insert(BTreeNode* parent, BTreeNode* child, int x) {
        int i = lowerBound(child, x);
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

    void deleteNode(BTreeNode* curr) {
        curr->children.clear();
        delete curr;
    }

    void fillInorder(BTreeNode* curr, vector<int>& inorder) {
        if (!curr) {
            return;
        }
        int kn = curr->keys.size();
        for (int i = 0; i < kn; i++) {
            if (!curr->leaf) {
                fillInorder(curr->children[i], inorder);
            }
            inorder.push_back(curr->keys[i]);
        }
        if (!curr->leaf) {
            fillInorder(curr->children[kn], inorder);
        }
    }

    void fillInorderString(BTreeNode* curr, string& inorder) {
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
    BTree(int k) : k(k), root(nullptr) {}

    bool search(int x) {
        return search(root, x) != nullptr;
    }

    void insert(int x) {
        if (!root) {
            root = new BTreeNode();
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

    friend ostream& operator<<(ostream& os, BTree& tree);

    ~BTree() {
        delete root;
    }
};

ostream& operator<<(ostream& os, BTree& tree) {
    string s;
    tree.fillInorderString(tree.root, s);
    os << s;
    return os;
}

class TwoThreeTree : public BTree {
public:
    TwoThreeTree() : BTree(2) {}
};

int main() {
    TwoThreeTree tree;
    for (int i = 1; i <= 10; i++) {
        tree.insert(i);
        cout << "Inserted " << i << ": " << tree << "\n";
    }
    vector<int> result = tree.traverse();
    cout << "Traverse: ";
    for (int x: result) {
        cout << x << " ";
    }
    cout << "\nTree: " << tree << "\n";
    return 0;
}