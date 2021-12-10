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
    }

    int pop()
    {
        if (this->isEmpty())
            cout << "Underflow: Stack is empty \n";
        else
            return arr[top_idx--];
    }

    int top()
    {
        if (this->isEmpty())
            cout << "Stack is empty \n";
        else
            return arr[top_idx];
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

class minStack2 : public stack
{
private:
    stack minArr;
    int mini;

public:
    void push(int data)
    {
        if (minArr.isEmpty())
        {
            mini = data;
            minArr.push(data);
        }
        else if (data < mini)
        {
            minArr.push(2 * data - mini);
            mini = data;
        }
        else
            minArr.push(data);
    }

    int pop()
    {
        if (minArr.isEmpty())
            cout << "Underflow: Stack is empty \n";
        else
        {
            int rem = minArr.pop();
            if (rem < mini)
                mini = 2 * mini - rem;
        }
    }

    int top()
    {
        if (this->isEmpty())
            cout << "Stack is empty \n";
        else
            return minArr.top() < mini 
                        ? mini 
                        : minArr.top();
    }

    int min()
    {
        if (minArr.isEmpty())
            cout << "Stack is empty \n";
        else
            return mini;
    }
};

int main()
{
    minStack2 s;
    s.push(10);
    s.push(50);
    s.push(5);
    s.push(30);
    s.push(20);
    cout << "Current stack: \n 20 -> TOP \n 30 \n 5 \n 50 \n 10 \n";
    cout << "Minimum element: " << s.min() << '\n';
    s.pop();
    s.pop();
    s.pop();
    cout << "Minimum element after 3 pops: " << s.min() << '\n';
    return 0;
}