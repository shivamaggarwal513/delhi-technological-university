#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class BTreeNode {
private:
    bool leaf;
    vector<int> keys;
    vector<BTreeNode*> children;

    bool isFull(int t) {
        return keys.size() == 2 * t - 1;
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
private:
    int t;
    BTreeNode* root;

    int lowerBound(BTreeNode* curr, int k) {
        return lower_bound(curr->keys.begin(), curr->keys.end(), k) - curr->keys.begin();
    }

    BTreeNode* getPredecessor(BTreeNode* curr, int k) {
        int i = lowerBound(curr, k);
        curr = curr->children[i];
        while (!curr->leaf) {
            curr = curr->children.back();
        }
        return curr;
    }

    BTreeNode* getSuccessor(BTreeNode* curr, int k) {
        int i = lowerBound(curr, k);
        curr = curr->children[i + 1];
        while (!curr->leaf) {
            curr = curr->children.front();
        }
        return curr;
    }

    BTreeNode* search(BTreeNode* curr, int k) {
        if (!curr) {
            return nullptr;
        }
        int i = lowerBound(curr, k);
        if (i != curr->keys.size() && curr->keys[i] == k) {
            return curr;
        }
        return !curr->leaf ? search(curr->children[i], k) : nullptr;
    }

    void deleteNode(BTreeNode* curr) {
        curr->children.clear();
        delete curr;
    }

    void splitChild(BTreeNode* parent, int childIndex) {
        BTreeNode* child1 = parent->children[childIndex];
        BTreeNode* child2 = new BTreeNode(child1->leaf);
        parent->keys.insert(parent->keys.begin() + childIndex, child1->keys[t - 1]);
        parent->children.insert(parent->children.begin() + childIndex + 1, child2);
        for (int i = t; i < 2 * t - 1; i++) {
            child2->keys.push_back(child1->keys[i]);
        }
        if (!child1->leaf) {
            for (int i = t; i < 2 * t; i++) {
                child2->children.push_back(child1->children[i]);
            }
            child1->children.resize(t);
        }
        child1->keys.resize(t - 1);
    }

    void mergeChild(BTreeNode* parent, int childIndex) {
        BTreeNode* child1 = parent->children[childIndex];
        BTreeNode* child2 = parent->children[childIndex + 1];
        child1->keys.push_back(parent->keys[childIndex]);
        parent->keys.erase(parent->keys.begin() + childIndex);
        parent->children.erase(parent->children.begin() + childIndex + 1);
        for (int i = 0; i < t - 1; i++) {
            child1->keys.push_back(child2->keys[i]);
        }
        if (!child1->leaf) {
            for (int i = 0; i < t; i++) {
                child1->children.push_back(child2->children[i]);
            }
        }
        deleteNode(child2);
    }

    void insert(BTreeNode* curr, int k) {
        int i = lowerBound(curr, k);
        if (curr->leaf) {
            curr->keys.insert(curr->keys.begin() + i, k);
            return;
        }
        if (curr->children[i]->isFull(t)) {
            splitChild(curr, i);
            i += curr->keys[i] < k;
        }
        insert(curr->children[i], k);
    }

    void remove(BTreeNode* curr, int k) {
        int i = lowerBound(curr, k);
        if (i < curr->keys.size() && curr->keys[i] == k) {
            if (curr->leaf) {
                curr->keys.erase(curr->keys.begin() + i);
            } else {
                if (curr->children[i]->keys.size() >= t) {
                    BTreeNode* pred = getPredecessor(curr, k);
                    curr->keys[i] = pred->keys.back();
                    remove(curr->children[i], pred->keys.back());
                } else if (curr->children[i + 1]->keys.size() >= t) {
                    BTreeNode* succ = getSuccessor(curr, k);
                    curr->keys[i] = succ->keys.front();
                    remove(curr->children[i + 1], succ->keys.front());
                } else {
                    mergeChild(curr, i);
                    remove(curr->children[i], k);
                }
            }
            return;
        }
        if (curr->leaf) {
            return;
        }
        if (curr->children[i]->keys.size() == t - 1) {
            if (i > 0 && curr->children[i - 1]->keys.size() >= t) {
                borrowFromPrev(curr, i);
            } else if (i != curr->children.size() - 1 && curr->children[i + 1]->keys.size() >= t) {
                borrowFromNext(curr, i);
            } else {
                if (i != curr->children.size() - 1) {
                    mergeChild(curr, i);
                } else {
                    mergeChild(curr, --i);
                }
            }
        }
        remove(curr->children[i], k);
    }

    void borrowFromPrev(BTreeNode* parent, int childIndex) {
        BTreeNode* child1 = parent->children[childIndex - 1];
        BTreeNode* child2 = parent->children[childIndex];
        child2->keys.insert(child2->keys.begin(), parent->keys[childIndex - 1]);
        parent->keys[childIndex - 1] = child1->keys.back();
        child1->keys.pop_back();
        if (!child1->leaf) {
            child2->children.insert(child2->children.begin(), child1->children.back());
            child1->children.pop_back();
        }
    }

    void borrowFromNext(BTreeNode* parent, int childIndex) {
        BTreeNode* child1 = parent->children[childIndex];
        BTreeNode* child2 = parent->children[childIndex + 1];
        child1->keys.push_back(parent->keys[childIndex]);
        parent->keys[childIndex] = child2->keys.front();
        child2->keys.erase(child2->keys.begin());
        if (!child2->leaf) {
            child1->children.push_back(child2->children.front());
            child2->children.erase(child2->children.begin());
        }
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
    BTree(int t) : t(t), root(nullptr) {}

    bool search(int k) {
        return search(root, k) != nullptr;
    }

    void insert(int k) {
        if (!root) {
            root = new BTreeNode();
            root->keys.push_back(k);
            return;
        }
        if (root->isFull(t)) {
            BTreeNode* parent = new BTreeNode(false);
            parent->children.push_back(root);
            splitChild(parent, 0);
            root = parent;
        }
        insert(root, k);
    }

    void remove(int k) {
        if (!root) {
            return;
        }
        remove(root, k);
        if (root->keys.empty()) {
            BTreeNode* toDel = root;
            if (root->leaf) {
                root = nullptr;
            } else {
                root = root->children[0];
            }
            deleteNode(toDel);
        }
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

int main() {
    BTree tree(3);
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
    for (int i = 10; i >= 1; i--) {
        tree.remove(i);
        cout << "Removed " << i << ": " << tree << "\n";
    }
    return 0;
}