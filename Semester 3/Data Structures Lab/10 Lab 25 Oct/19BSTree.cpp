#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isBST(Node* root, Node* l = nullptr, Node* r = nullptr)
{
    if (root == nullptr)
        return true;
    else if (l != nullptr && root->data <= l->data)
        return false;
    else if (r != nullptr && root->data >= r->data)
        return false;
    else
        return isBST(root->left, l, root) && isBST(root->right, root, r);
}

int main()
{
    Node* root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(50);
    root->left->left = new Node(10);
    root->left->right = new Node(40);

    if (isBST(root))
        cout << "Given is a Binary Search Tree \n";
    else
        cout << "Given is not a Binary Search Tree \n";
    return 0;
}