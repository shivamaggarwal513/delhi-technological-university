#include <iostream>
#include <string>
using namespace std;

enum Color { red, black };

template <class T> class RBTreeNode;
template <class T> class RBTree;
template <typename T> ostream& operator<<(ostream& os, RBTree<T>& tree);

template <class T> class RBTreeNode {
private:
    T val;
    Color color;
    RBTreeNode<T>* parent, *left, *right;

public:
    RBTreeNode(
        Color color = red,
        RBTreeNode<T>* parent = nullptr,
        RBTreeNode<T>* left = nullptr,
        RBTreeNode<T>* right = nullptr
    ) : color(color), parent(parent), left(left), right(right) {}

    RBTreeNode(
        T val,
        Color color = red,
        RBTreeNode<T>* parent = nullptr,
        RBTreeNode<T>* left = nullptr,
        RBTreeNode<T>* right = nullptr
    ) : val(val), color(color), parent(parent), left(left), right(right) {}

    ~RBTreeNode() {
        delete left;
        delete right;
    }

    friend class RBTree<T>;
};

template <class T> class RBTree {
private:
    RBTreeNode<T>* root, *nil;

    void leftRotate(RBTreeNode<T>* x) {
        RBTreeNode<T>* y = x->right;
        x->right = y->left;
        if (x->right != nil) {
            x->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(RBTreeNode<T>* x) {
        RBTreeNode<T>* y = x->left;
        x->left = y->right;
        if (x->left != nil) {
            x->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->right = x;
        x->parent = y;
    }

    void insertFixUp(RBTreeNode<T>* x) {
        while (x->parent->color == red) {
            RBTreeNode<T>* parent = x->parent, *grandParent = parent->parent;
            if (parent == grandParent->left) {
                RBTreeNode<T>* uncle = grandParent->right;
                if (uncle->color == red) {
                    parent->color = uncle->color = black;
                    grandParent->color = red;
                    x = grandParent;
                } else {
                    if (x == parent->right) {
                        x = parent;
                        leftRotate(parent);
                    }
                    x->parent->color = black;
                    grandParent->color = red;
                    rightRotate(grandParent);
                }
            } else {
                RBTreeNode<T>* uncle = grandParent->left;
                if (uncle->color == red) {
                    parent->color = uncle->color = black;
                    grandParent->color = red;
                    x = grandParent;
                } else {
                    if (x == parent->left) {
                        x = parent;
                        rightRotate(parent);
                    }
                    x->parent->color = black;
                    grandParent->color = red;
                    leftRotate(grandParent);
                }
            }
        }
        root->color = black;
    }

    void fillPreorderString(RBTreeNode<T>* curr, string& s) {
        s.push_back('(');
        if (curr != nil) {
            s += to_string(curr->val) + (curr->color == black ? 'B' : 'R');
            if (curr->left != nil || curr->right != nil) {
                fillPreorderString(curr->left, s);
                fillPreorderString(curr->right, s);
            }
        }
        s.push_back(')');
    }

public:
    RBTree() {
        root = nil = new RBTreeNode<T>(black);
    }

    int blackHeight() {
        int bh = 0;
        for (RBTreeNode<T>* x = root; x != nil; x = x->left) {
            bh += x->color == black;
        }
        return bh;
    }

    void insert(T val) {
        RBTreeNode<T>* x = root, *y = nil, *z = new RBTreeNode<T>(val, red, nil, nil, nil);
        while (x != nil) {
            y = x;
            x = z->val < x->val ? x->left : x->right;
        }
        z->parent = y;
        if (y == nil) {
            root = z;
        } else if (z->val < y->val) {
            y->left = z;
        } else {
            y->right = z;
        }
        insertFixUp(z);
    }

    ~RBTree() {
        delete root;
    }
    
    friend ostream& operator<<<>(ostream& os, RBTree<T>& tree);
};

template <typename T> ostream& operator<<(ostream& os, RBTree<T>& tree) {
    string s;
    tree.fillPreorderString(tree.root, s);
    os << s;
    return os;
}

int main() {
    RBTree<int> tree;
    for (int i = 1; i <= 10; i++) {
        tree.insert(i);
        cout << "Inserted " << i << ":\tBlack Height = " << tree.blackHeight() << "\tTree: " << tree << "\n";
    }
    return 0;
}