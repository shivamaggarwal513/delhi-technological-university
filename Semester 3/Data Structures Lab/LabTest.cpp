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

int max(int x, int y) 
{
    return x > y ? x : y;
}

int height(Node* root)
{
    if (root == nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int longestPath(Node* root)
{
    if (root == nullptr)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    int leftPath = longestPath(root->left);
    int rightPath = longestPath(root->right);

    return max(leftHeight + rightHeight + 1, max(leftPath, rightPath));
}

int main()
{
    Node* root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(50);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    root->left->left->right = new Node(60);

    //       30
    //      /  \ 
    //     20  50
    //    / \ 
    //  10   40
    //   \ 
    //    60
    //  Longest path: 60 - 10 - 20 - 30 - 50
	
	cout << "No. of nodes in longest path: " << longestPath(root) << " \n";

	return 0;
}