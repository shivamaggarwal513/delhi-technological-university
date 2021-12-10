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
    cout << "Linked list: ";
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL \n";
}

void insertBeg(Node** head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = *head;
    *head = newNode;
}

void insertLL(Node** head, int val, int index)
{
    Node* newNode = new Node(val);
    if (*head == nullptr)
        *head = newNode;
    else
    {
        Node* temp = *head;
        while (--index)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertEnd(Node** head, int val)
{
    Node* newNode = new Node(val);
    if (*head == nullptr)
        *head = newNode;
    else
    {
        Node* last = *head;
        while (last->next != nullptr)
            last = last->next;
        last->next = newNode;
    }
}

int main()
{
    Node* head = new Node(1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    displayLL(&head);

    int cont = 1, choice, val, index;
    while (cont)
    {
        cout << "1. Insert at beginning \n"
             << "2. Insert at end \n"
             << "3. Insert at specific position \n\n"
             << "Enter your choice: "; 
             cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter value to be inserted: "; cin >> val;
                insertBeg(&head, val);
                displayLL(&head);
                break;
            case 2:
                cout << "Enter value to be inserted: "; cin >> val;
                insertEnd(&head, val);
                displayLL(&head);
                break;
            case 3:
                cout << "Enter value to be inserted: "; cin >> val;
                cout << "Enter index of insertion: "; cin >> index;
                insertLL(&head, val, index);
                displayLL(&head);
                break;
        }
        cout << "Enter 0 to exit: "; cin >> cont;
    }
    return 0;
}