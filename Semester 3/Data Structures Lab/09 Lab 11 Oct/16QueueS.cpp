#include <iostream>
#include <stack>
using namespace std;

class queue
{
private:
    stack<int> s, sTemp;

public:
    void enqueue(int data)
    {
        while (!s.empty())
        {
            sTemp.push(s.top());
            s.pop();
        }
        s.push(data);
        while (!sTemp.empty())
        {
            s.push(sTemp.top());
            sTemp.pop();
        }
    }

    int dequeue()
    {
        if (s.empty())
            cout << "Underflow: Queue is empty \n\n";
        else
        {
            int popData = s.top();
            s.pop();
            return popData;
        }
    }

    int front()
    {
        if (s.empty())
            cout << "Underflow: Queue is empty \n\n";
        else
            return s.top();
    }
};

int main()
{
    queue q;
    int choice, data;
    cout << "0. Exit \n"
        << "1. Enqueue \n"
        << "2. Dequeue \n"
        << "3. Front \n"
        << "\nEnter choice: "; cin >> choice;
    while (choice != 0)
    {
        switch(choice)
        {
            case 1:
                cout << "Element: "; cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Element at front: " << q.front() << " \n";
                break;
        }
        cout << "Enter choice: "; cin >> choice;
    }
    return 0;
}