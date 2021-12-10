#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        height = 1;
        left = right = nullptr;
    }
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(Node* root)
{
    if (root == nullptr)
        return 0;
    return root->height;
}

int balanceFactor(Node *root)
{
    if (root == nullptr)
        return 0;
    return height(root->left) - height(root->right);
}

Node* minDataNode(Node* root)
{
    Node* temp = root;
    while (temp->left != nullptr)
        temp = temp->left;
    return temp;
}

void preorder(Node* root)
{
	if (root != nullptr)
	{
        cout << root->data << " -> ";
		preorder(root->left);
		preorder(root->right);
	}
}

Node* rightRotate(Node* root)
{
    Node* newRoot = root->left;

    Node* temp = newRoot->right;
    newRoot->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

Node* leftRotate(Node* root)
{
    Node* newRoot = root->right;

    Node* temp = newRoot->left;
    newRoot->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

Node* insert(Node* root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;
    
    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = height(root->left) - height(root->right);
    
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);
    
    if (balance < -1 && data > root->right->data)
        return leftRotate(root);
    
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

Node* deleteNode(Node* root, int data)
{
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if ((root->left == nullptr) || (root->right == nullptr))
        {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            Node* temp = minDataNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
	if (root == nullptr)
	    return root;
    
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = balanceFactor(root);

	if (balance > 1 && balanceFactor(root->left) >= 0)
		return rightRotate(root);

	if (balance > 1 && balanceFactor(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && balanceFactor(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 && balanceFactor(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

int main()
{
    Node* root = nullptr;

    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 11);
    root = insert(root, 7);
    root = insert(root, 53);
    root = insert(root, 4);
    root = insert(root, 13);
    root = insert(root, 12);
    root = insert(root, 8);

    //       14
    //      /  \ 
    //     11  17
    //    / \    \ 
    //   7   12   53
    //  / \   \ 
    // 4   8   13

    cout << "Preorder travesal of AVL tree: \n";
    preorder(root);
    cout << "END \n";

    root = deleteNode(root, 11);

    //       14
    //      /  \ 
    //     12  17
    //    / \    \ 
    //   7   13   53
    //  / \ 
    // 4   8

    cout << "Preorder travesal after deletion of 11: \n";
    preorder(root);
    cout << "END \n";

    return 0;
}