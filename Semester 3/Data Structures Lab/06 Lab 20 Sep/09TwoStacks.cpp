#include <iostream>
using namespace std;

class TwoStack
{
private:
    int arr[100];
    int top_idx1;
    int top_idx2;
    
public:
    TwoStack() { top_idx1 = -1; top_idx2 = 100; }

    void push(int data, int choice)
    {
        if (this->isFull())
            cout << "Overflow: TwoStack is full \n";
        else if (choice == 1)
            arr[++top_idx1] = data;
        else
            arr[--top_idx2] = data;
        cout << " \n";
    }

    void pop(int choice)
    {
        if (this->isEmpty(choice))
            cout << "Underflow: Stack" << choice << " is empty \n\n";
        else if (choice == 1)
            cout << "Element deleted: " << arr[top_idx1--] << " \n\n";
        else
            cout << "Element deleted: " << arr[top_idx2++] << " \n\n";
    }

    void top(int choice)
    {
        if(this->isEmpty(choice))
            cout << "TwoStack is empty \n\n";
        else if (choice == 1)
            cout << "Element at top: " << arr[top_idx1] << " \n\n";
        else
            cout << "Element at top: " << arr[top_idx2] << " \n\n";
    }

    bool isEmpty(int choice)
    {
        if (choice == 1)
            return top_idx1 == -1;
        else
            return top_idx2 == 100;
    }

    bool isFull()
    {
        return top_idx1 + 1 == top_idx2;
    }
};

int main()
{
    TwoStack s;
    int choice, stack_choice, data;
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
                cout << "Stack choice: "; cin >> stack_choice;
                s.push(data, stack_choice);
                break;
            case 2:
                cout << "Stack choice: "; cin >> stack_choice;
                s.pop(stack_choice);
                break;
            case 3:
                cout << "Stack choice: "; cin >> stack_choice;
                s.top(stack_choice);
                break;
            case 4:
                cout << "Stack choice: "; cin >> stack_choice;
                if (s.isEmpty(stack_choice))
                    cout << "Stack " << stack_choice << " is empty \n\n";
                else
                    cout << "Stack " << stack_choice << " is not empty \n\n";
                break;
            case 5:
                if (s.isFull())
                    cout << "TwoStack is full \n\n";
                else
                    cout << "TwoStack is not full \n\n";
                break;
        }
        cout << "Enter choice: "; cin >> choice;
    }
    return 0;
}