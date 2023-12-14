#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

enum Color { red, black };

class Interval {
private:
    int low, high;

public:
    Interval(int low = 0, int high = 0) : low(low), high(high) {}

    Interval(const Interval& interval) {
        low = interval.low;
        high = interval.high;
    }

    bool overlap(Interval& interval) {
        return low <= interval.high && interval.low <= high;
    }

    friend class IntervalTreeNode;
    friend class IntervalTree;
    friend string to_string(Interval& interval);
    friend ostream& operator<<(ostream& os, Interval& interval);
};

string to_string(Interval& interval) {
    return "[" + to_string(interval.low) + "," + to_string(interval.high) + "]";
}

ostream& operator<<(ostream& os, Interval& interval) {
    os << to_string(interval);
    return os;
}

class IntervalTreeNode {
private:
    Interval interval;
    int maximum;
    Color color;
    IntervalTreeNode* parent, *left, *right;

public:
    IntervalTreeNode(
        Color color = red,
        IntervalTreeNode* parent = nullptr,
        IntervalTreeNode* left = nullptr,
        IntervalTreeNode* right = nullptr
    ) : maximum(0), color(color), parent(parent), left(left), right(right) {}

    IntervalTreeNode(
        Interval interval,
        int maximum = 0,
        Color color = red,
        IntervalTreeNode* parent = nullptr,
        IntervalTreeNode* left = nullptr,
        IntervalTreeNode* right = nullptr
    ) : interval(interval), maximum(maximum), color(color), parent(parent), left(left), right(right) {}

    ~IntervalTreeNode() {
        delete left;
        delete right;
    }

    void updateMaximum() {
        maximum = max({interval.high, left->maximum, right->maximum});
    }

    friend class IntervalTree;
    friend string to_string(IntervalTreeNode& x);
    friend ostream& operator<<(ostream& os, IntervalTreeNode& x);
};

string to_string(IntervalTreeNode& x) {
    return "[" + to_string(x.interval) + "," + to_string(x.maximum) + "]";
}

ostream& operator<<(ostream& os, IntervalTreeNode& x) {
    os << to_string(x);
    return os;
}

class IntervalTree {
private:
    IntervalTreeNode* root, *nil;

    void leftRotate(IntervalTreeNode* x) {
        IntervalTreeNode* y = x->right;
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
        x->updateMaximum();
        y->updateMaximum();
    }

    void rightRotate(IntervalTreeNode* x) {
        IntervalTreeNode* y = x->left;
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
        x->updateMaximum();
        y->updateMaximum();
    }

    void insertFixUp(IntervalTreeNode* x) {
        while (x->parent->color == red) {
            IntervalTreeNode* parent = x->parent, *grandParent = parent->parent;
            if (parent == grandParent->left) {
                IntervalTreeNode* uncle = grandParent->right;
                if (uncle->color == red) {
                    parent->color = uncle->color = black;
                    grandParent->color = red;
                    x->updateMaximum();
                    parent->updateMaximum();
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
                IntervalTreeNode* uncle = grandParent->left;
                if (uncle->color == red) {
                    parent->color = uncle->color = black;
                    grandParent->color = red;
                    x->updateMaximum();
                    parent->updateMaximum();
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
        while (x != nil) {
            x->updateMaximum();
            x = x->parent;
        }
        root->color = black;
    }

    void fillPreorder(IntervalTreeNode* curr, vector<string>& result) {
        if (curr == nil) {
            return;
        }
        result.push_back(to_string(*curr));
        fillPreorder(curr->left, result);
        fillPreorder(curr->right, result);
    }

    void fillPreorderString(IntervalTreeNode* curr, string& s) {
        s.push_back('(');
        if (curr != nil) {
            s += to_string(*curr);
            if (curr->left != nil || curr->right != nil) {
                fillPreorderString(curr->left, s);
                fillPreorderString(curr->right, s);
            }
        }
        s.push_back(')');
    }

public:
    IntervalTree() {
        root = nil = new IntervalTreeNode(black);
    }

    int blackHeight() {
        int bh = 0;
        for (IntervalTreeNode* x = root; x != nil; x = x->left) {
            bh += x->color == black;
        }
        return bh;
    }

    string search(Interval interval) {
        IntervalTreeNode* x = root;
        while (x != nil && !interval.overlap(x->interval)) {
            if (x->left != nil && x->left->maximum >= interval.low) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        return x != nil ? to_string(x->interval) : "NIL";
    }

    void insert(Interval interval) {
        IntervalTreeNode* x = root, *y = nil, *z = new IntervalTreeNode(interval, interval.high, red, nil, nil, nil);
        while (x != nil) {
            y = x;
            x = z->interval.low < x->interval.low ? x->left : x->right;
        }
        z->parent = y;
        if (y == nil) {
            root = z;
        } else if (z->interval.low < y->interval.low) {
            y->left = z;
        } else {
            y->right = z;
        }
        insertFixUp(z);
    }

    vector<string> preorder() {
        vector<string> result;
        fillPreorder(root, result);
        return result;
    }

    ~IntervalTree() {
        delete root;
    }
    
    friend string to_string(IntervalTree& tree);
    friend ostream& operator<<(ostream& os, IntervalTree& tree);
};

string to_string(IntervalTree& x) {
    string result;
    x.fillPreorderString(x.root, result);
    return result;
}

ostream& operator<<(ostream& os, IntervalTree& tree) {
    os << to_string(tree);
    return os;
}

int main() {
    IntervalTree tree;
    vector<Interval> intervals{{5, 12}, {6, 10}, {15, 23}, {16, 21}, {19, 20}, {25, 30}};
    for (Interval& interval: intervals) {
        tree.insert(interval);
        cout << "Inserted " << interval << ":\t" << tree << "\n";
    }
    vector<string> preorder = tree.preorder();
    cout << "\nPreorder: ";
    for (string& s: preorder) {
        cout << s << " ";
    }
    cout << "\n\n";
    Interval interval(27, 28);
    cout << "Search " << interval << ": " << tree.search(interval) << "\n";
    return 0;
}