#include <iostream>
#include <functional>
using namespace std;

template <class T>
class FibonacciHeapNode {
public:
    T val;
    bool mark;
    int degree;
    FibonacciHeapNode<T>* parent, *child, *left, *right;

    FibonacciHeapNode()
        : mark(false), degree(0), parent(nullptr), child(nullptr), left(this), right(this) {}
    
    ~FibonacciHeapNode() {
        FibonacciHeapNode<T>* t, *f = child;
        for (FibonacciHeapNode<T>* c = child; c && c->right != f; c = t) {
            t = c->right;
            delete c;
        }
        delete f;
    }
};

template <class T, class Pr = less<T>>
class FibonacciHeap {
private:
    int n;
    FibonacciHeapNode<T>* root, *optima;

public:
    FibonacciHeap() : n(0), root(new FibonacciHeapNode<T>()), optima(nullptr) {}

    void push(int val) {
        FibonacciHeapNode<T>* x = new FibonacciHeapNode<T>();
        x->val = val;
        if (n == 0) {
            optima = root->child = x;
        } else {
            x->right = root->child->right;
            root->child->right->left = x;
            root->child->right = x;
            x->left = root->child;
            if (Pr()(optima->val, x->val)) {
                optima = x;
            }
        }
        x->parent = root;
        n++;
    }

    int top() {
        return optima ? optima->val : -1;
    }

    ~FibonacciHeap() {
        delete root;
    }
};

int main() {
    FibonacciHeap<int, greater<int>> heap;
    for (int i = 10; i > 0; i--) {
        heap.push(i);
        cout << heap.top() << " ";
    }
    return 0;
}