#include <iostream>
#include <string>
using namespace std;

template <typename T>
class deque
{
private:
    T arr[100];
    int front, rear;

public:
    deque() { front = -1; rear = 0; }

    void pushFront(T data)
    {
        if (this->isFull())
        {
            cout << "Overflow: Deque is full \n\n";
            return;
        }
        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = 99;
        else
            front--;
        arr[front] = data;
    }

    void pushBack(T data)
    {
        if (this->isFull())
        {
            cout << "Overflow: Deque is full \n\n";
            return;
        }
        if (front == -1)
            front = rear = 0;
        else if (rear == 99)
            rear = 0;
        else
            rear++;
        arr[rear] = data;
    }

    void popFront()
    {
        if (this->isEmpty())
        {
            cout << "Underflow: Deque is empty \n\n";
            return;
        }
        if (front == rear)
            front = rear = -1;
        else if (front == 99)
            front = 0;
        else
            front++;
    }

    void popBack()
    {
        if (this->isEmpty())
        {
            cout << "Underflow: Deque is empty \n\n";
            return;
        }
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = 99;
        else
            rear--;
    }

    bool isFull()
    {
        return ((front == 0 && rear == 99) || (front == rear + 1));
    }

    bool isEmpty()
    {
        return front == -1;
    }

    char Front()
    {
        if (this->isEmpty())
        {
            cout << "Underflow: Deque is empty \n\n";
            return -1;
        }
        return arr[front];
    }

    char Back()
    {
        if (this->isEmpty() || rear < 0)
        {
            cout << "Underflow: Deque is empty \n\n";
            return -1;
        }
        return arr[rear];
    }
};


bool isPalindrome(string str)
{
    int i;
    char f, l;
    bool res = true;
    deque<char> d;
    for (i = 0; i < str.size(); i++)
        d.pushBack(str[i]);
    for (i = 0; i < str.size() / 2 && res != false; i++)
    {
        f = d.Front(); d.popFront();
        l = d.Back(); d.popBack();
        if (f != l)
            res = false;
    }
    return res;
}

int main()
{
    string str;
    cout << "Enter a string: "; cin >> str;
    if (isPalindrome(str))
        cout << "\"" << str << "\" is a palindrome \n";
    else
        cout << "\"" << str << "\" is not a palindrome \n";
    return 0;
}