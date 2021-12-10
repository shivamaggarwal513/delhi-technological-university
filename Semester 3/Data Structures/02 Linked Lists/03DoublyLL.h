#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
} node; 
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

void displayDLL(Node** head)
{
    Node* temp = *head;
    while (temp->next != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << temp->data << " -> NULL \n";
}
node* createLL()
{
    int n, val;
    printf("Enter size of linked list (>= 1): ");
    scanf("%d", &n);
    node* head = NULL;
    node* temp = (node*)malloc(sizeof(node));
    head = temp;
    printf("Enter %d elements: \n", n);
    scanf("%d", &val);
    temp->data = val;
    temp->next = NULL;
    while (--n)
    {
        node* temp1 = (node*)malloc(sizeof(node));
        temp->next = temp1;
        temp = temp1;
        scanf("%d", &val);
        temp1->data = val;
        temp1->next = NULL;
    }
    return head;
}

void displayLL(node** head)
{
    node* temp = *head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* searchLL(node** head, int k)
{
    node* temp = *head;
    while (temp != NULL)
    {
        if (temp->data == k)
            break;
        temp = temp->next;
    }
    return temp;
}

void insertBeg(node** head, int val)
{
    node* temp = (node*)malloc(sizeof(node*));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}

void insertEnd(node** head, int val)
{
    node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    node* temp1 = (node*)malloc(sizeof(node*));
    temp->next = temp1;
    temp1->data = val;
    temp1->next = NULL;
}

void insertLL(node** head, int val, int num)
{
    node* temp = *head;
    while (temp->data != num)
        temp = temp->next;
    node* temp1 = (node*)malloc(sizeof(node*));
    temp1->data = val;
    temp1->next = temp->next;
    temp->next = temp1;
}

void deleteBeg(node** head)
{
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(node** head)
{
    node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    node* temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
}

void deleteLL(node** head, int val)
{
    node* temp = *head;
    while (temp->next->data != val)
        temp = temp->next;
    node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}