#include <iostream>
#include <functional>
#include <vector>
using namespace std;

template <class T>
class BinomialTree {
public:
    T val;
    int degree;
    BinomialTree<T>* parent, *next, *child;

    BinomialTree() 
        : degree(-1), parent(nullptr), next(nullptr), child(nullptr) {}

    BinomialTree(
        T val,
        BinomialTree<T>* child = nullptr,
        BinomialTree<T>* next = nullptr,
        BinomialTree<T>* parent = nullptr
    ) : val(val), child(child), next(next), parent(parent) {
        degree = child ? child->degree + 1 : 0;
    }

    BinomialTree<T>* addSubTree(BinomialTree<T>* tree) {
        tree->next = child;
        tree->parent = this;
        child = tree;
        degree++;
        return this;
    }

    ~BinomialTree() {
        BinomialTree<T>* t;
        for (BinomialTree<T>* c = child; c; c = t) {
            t = c->next;
            delete c;
        }
    }
};

template <class T, class Pr = less<T>>
class BinomialHeap {
private:
    BinomialTree<T>* root;

    BinomialTree<T>* mergeTree(BinomialTree<T>* p, BinomialTree<T>* q) {
        return Pr()(p->val, q->val) ? q->addSubTree(p) : p->addSubTree(q);
    }

public:
    BinomialHeap() : root(new BinomialTree<T>()) {}

    BinomialHeap(int val) : root(new BinomialTree<T>()) {
        root->child = new BinomialTree<T>(val);
    }

    void merge(BinomialHeap<T, Pr>* heap) {
        BinomialTree<T>* h1 = root->child, *h2 = heap->root->child;
        BinomialTree<T> dummy, *curr = &dummy, *carry = nullptr;
        while (h1 || h2 || carry) {
            vector<BinomialTree<T>*> x;
            if (!carry) {
                if (h1 && (!h2 || h1->degree <= h2->degree)) {
                    x.push_back(h1);
                    h1 = h1->next;
                }
                if (h2 && (!h1 || h1->degree >= h2->degree)) {
                    x.push_back(h2);
                    h2 = h2->next;
                }
            } else {
                x.push_back(carry);
                if (h1 && h1->degree == carry->degree) {
                    x.push_back(h1);
                    h1 = h1->next;
                }
                if (h2 && h2->degree == carry->degree) {
                    x.push_back(h2);
                    h2 = h2->next;
                }
                carry = nullptr;
            }
            if (x.size() == 1) {
                curr = curr->next = x[0];
            } else if (x.size() == 2) {
                carry = mergeTree(x[0], x[1]);
            } else {
                curr = curr->next = x[0];
                carry = mergeTree(x[1], x[2]);
            }
        }
        root->child = dummy.next;
        dummy.next->parent = root;
    }

    void push(int val) {
        merge(new BinomialHeap<T, Pr>(val));
    }

    int top() {
        if (!root->child) {
            return -1;
        }
        BinomialTree<T>* curr = root->child;
        int optima = curr->val;
        while (curr) {
            if (Pr()(optima, curr->val)) {
                optima = curr->val;
            }
            curr = curr->next;
        }
        return optima;
    }

    ~BinomialHeap() {
        delete root;
    }
};

int main() {
    BinomialHeap<int, greater<int>> heap;
    for (int i = 10; i > 0; i--) {
        heap.push(i);
        cout << heap.top() << " ";
    }
    return 0;
}