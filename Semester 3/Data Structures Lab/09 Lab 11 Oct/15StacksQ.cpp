#include <iostream>
#include <queue>
using namespace std;

class stack
{
private:
    queue<int> q, qTemp;

public:
    void push(int data)
    {
        qTemp.push(data);
        while (!q.empty())
        {
            qTemp.push(q.front());
            q.pop();
        }
        queue<int> qSwap = q;
        q = qTemp;
        qTemp = qSwap;
    }

    void pop()
    {
        if (q.empty())
            cout << "Underflow: Stack is empty \n\n";
        else
            q.pop();
    }

    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
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
                cout << "Element at top: " << s.top() << " \n";
                break;
        }
        cout << "Enter choice: "; cin >> choice;
    }
    return 0;
}