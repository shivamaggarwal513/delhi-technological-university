#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void displayLL(Node** head)
{
    Node* temp = *head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL \n";
}

int main()
{
    int n, i, val;
    Node *head, *temp, *temp1, *front, *back;
    cout << "Enter size of linked list (>= 1): "; cin >> n;
    cout << "Enter " << n << " elements: \n";
    cin >> val;
    temp = new Node(val);
    head = temp;
    front = temp;
    for (i = 1; i < n; i++)
    {
        cin >> val;
        temp1 = new Node(val);
        temp->next = temp1;
        temp = temp1;
    }
    temp = head;
    for (i = 0; i < n / 2; i++)
    {
        temp1 = temp;
        temp = temp->next;
    }
    back = temp;
    if (n % 2 == 1)
    {
        temp = temp1;
        while (temp->next->next)
            temp = temp->next;
        temp1->next = temp->next;
        temp->next = nullptr;
    }
    else
        temp1->next = nullptr;
    cout << "Front sub-list: \n";
    displayLL(&front);
    cout << "Back sub-list: \n";
    displayLL(&back);
    return 0;
}