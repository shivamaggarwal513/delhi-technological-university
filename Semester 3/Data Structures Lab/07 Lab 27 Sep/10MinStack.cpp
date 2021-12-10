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

class minStack : public stack
{
private:
    stack minArr;

public:
    void push(int data)
    {
        stack::push(data);
        if (this->isEmpty())
            minArr.push(data);
        else
        {
            int temp = minArr.pop();
            minArr.push(temp);
            (data < temp)
                ? minArr.push(data)
                : minArr.push(temp);
        }
    }

    int pop()
    {
        minArr.pop();
        return stack::pop();
    }

    int min()
    {
        return minArr.top();
    }
};

int main()
{
    minStack s;
    s.push(10);
    s.push(50);
    s.push(1);
    s.push(30);
    s.push(20);
    cout << "Current stack: \n 20 -> TOP \n 30 \n 1 \n 50 \n 10 \n";
    cout << "Minimum element: " << s.min() << '\n';
    s.pop();
    s.pop();
    s.pop();
    cout << "Minimum element after 3 pops: " << s.min() << '\n';
    return 0;
}