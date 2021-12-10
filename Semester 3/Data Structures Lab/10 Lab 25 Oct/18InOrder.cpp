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

void inorder(Node* root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    
    cout << "Inorder traversal: \n";
    inorder(root);
    cout << "END \n";
    return 0;
}