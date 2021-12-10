#include <iostream>
using namespace std;

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
            front = rear = 0;
            arr[rear] = data;
        }
        else
            arr[++rear] = data;
        cout << " \n";
    }

    void dequeue()
    {
        if (this->isEmpty())
            cout << "Underflow: Queue is empty \n\n";
        else
            cout << "Element deleted: " << arr[front++] << " \n\n";
    }

    void print()
    {
        cout << "Front <- ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << " <- Rear \n\n";
    }

    void peek()
    {
        if(this->isEmpty())
            cout << "Queue is empty \n\n";
        else
            cout << "Element at front: " << arr[front] << " \n\n";
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

int main()
{
    queue q;
    int choice, data;
    cout << "0. Exit \n"
        << "1. Enqueue \n"
        << "2. Dequeue \n"
        << "3. Print \n"
        << "4. Peek \n"
        << "5. isEmpty \n"
        << "6. isFull \n"
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
                q.print();
                break;
            case 4:
                q.peek();
                break;
            case 5:
                if (q.isEmpty())
                    cout << "Queue is empty \n\n";
                else
                    cout << "Queue is not empty \n\n";
                break;
            case 6:
                if (q.isFull())
                    cout << "Queue is full \n\n";
                else
                    cout << "Queue is not full \n\n";
                break;
        }
        cout << "Enter choice: "; cin >> choice;
    }
    return 0;
}