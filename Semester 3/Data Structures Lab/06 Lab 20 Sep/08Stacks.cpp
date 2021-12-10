#include <iostream>
using namespace std;

class stack
{
private:
    int arr[100];
    int top_idx;
    
public:
    stack() { top_idx = -1; }

    void push(int data)
    {
        if (this->isFull())
            cout << "Overflow: Stack is full \n";
        else
            arr[++top_idx] = data;
        cout << " \n";
    }

    void pop()
    {
        if (this->isEmpty())
            cout << "Underflow: Stack is empty \n\n";
        else
            cout << "Element deleted: " << arr[top_idx--] << " \n\n";
    }

    void top()
    {
        if(this->isEmpty())
            cout << "Stack is empty \n\n";
        else
            cout << "Element at top: " << arr[top_idx] << " \n\n";
    }

    bool isEmpty()
    {
        return top_idx == -1;
    }

    bool isFull()
    {
        return top_idx == 99;
    }
};

int main()
{
    stack s;
    int choice, data;
    cout << "0. Exit \n"
        << "1. Push \n"
        << "2. Pop \n"
        << "3. Top \n"
        << "4. isEmpty \n"
        << "5. isFull \n"
        << "\nEnter choice: "; cin >> choice;
    while (choice != 0)
    {
        switch(choice)
        {
            case 1:
                cout << "Element: "; cin >> data;
                s.push(data);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.top();
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty \n\n";
                else
                    cout << "Stack is not empty \n\n";
                break;
            case 5:
                if (s.isFull())
                    cout << "Stack is full \n\n";
                else
                    cout << "Stack is not full \n\n";
                break;
        }
        cout << "Enter choice: "; cin >> choice;
    }
    return 0;
}