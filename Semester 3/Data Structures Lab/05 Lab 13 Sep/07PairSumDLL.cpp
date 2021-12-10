#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* createDLL()
{
    int n, val;
    Node *head, *temp, *temp1;
    cout << "Enter size of doubly linked list (>= 1): "; cin >> n;
    cout << "Enter " << n << " elements: \n";
    cin >> val;
    temp = new Node(val);
    head = temp;
    while (--n)
    {
        cin >> val;
        temp1 = new Node(val);
        temp->next = temp1;
        temp1->prev = temp;
        temp = temp->next;
    }
    return head;
}

void pairSum(Node** head, int& p)
{
    int flag = 0;
    Node *front = *head, *back = *head;
    while (back->next != nullptr)
        back = back->next;
    cout << "Pairs of sum = " << p << " are: \n";
    while (front != back && back->next != front)
    {
        if (front->data + back->data == p)
        {
            cout << "(" << front->data << ", " << back->data << ")" << '\n';
            front = front->next;
            back = back->prev;
            flag = 1;
        }
        else if (front->data + back->data > p)
            back = back->prev;
        else
            front = front->next;
    }
    if (flag == 0)
        cout << "No pair present \n";
}

int main()
{
    int p;
    Node *head;
    head = createDLL();
    cout << "Enter the desired sum: "; cin >> p;
    pairSum(&head, p);
    return 0;
}