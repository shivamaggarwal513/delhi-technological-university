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
        {
            cout << "Element inserted to stack: " << data << " \n";
            arr[++top_idx] = data;
        }
    }

    void pop()
    {
        if (this->isEmpty())
            cout << "Underflow: Stack is empty \n";
        else
            cout << "Element deleted from stack: " << arr[top_idx--] << " \n";
    }

    int top()
    {
        if(!this->isEmpty())
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

class queue
{
private:
    int arr[100];
    int front, rear;
    
public:
    queue() { front = rear = -1; }

    void enqueue(int data)
    {
        if (this->isFull())
            cout << "Overflow: Queue is full \n";
        else if (this->isEmpty())
        {
            cout << "Element inserted to queue: " << data << " \n";
            front = rear = 0;
            arr[rear] = data;
        }
        else
        {
            cout << "Element inserted to queue: " << data << " \n";
            arr[++rear] = data;
        }
    }

    void dequeue()
    {
        if (this->isEmpty())
            cout << "Underflow: Queue is empty \n";
        else
            cout << "Element deleted from queue: " << arr[front++] << " \n";
    }

    void print()
    {
        cout << "Front <- ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << " <- Rear \n\n";
    }

    int peek()
    {
        if(!this->isEmpty())
            return arr[front];
    }

    int size()
    {
        return rear - front + 1;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    bool isFull()
    {
        return rear == 99;
    }
};

void revKQ(queue& q, int k)
{
    if (q.isEmpty())
        return;
    int i;
    stack s;
    for (i = 0; i < k; i++)
    {
        s.push(q.peek());
        q.dequeue();
    }

    while (!s.isEmpty())
    {
        q.enqueue(s.top());
        s.pop();
    }

    for (i = 0; i < q.size() - k; i++)
    {
        q.enqueue(q.peek());
        q.dequeue();
    }
}

int main()
{
    int k;
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    cout << "Queue: \n";
    q.print();

    cout << "Enter K (< 10): "; cin >> k; cout << " \n";
    revKQ(q, k);
    cout << "\nQueue after reversing: \n";
    q.print();
    
    return 0;
}