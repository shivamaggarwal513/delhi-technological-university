#include <iostream>
#include <stack>
#include <cmath>
#include <string>
using namespace std;

void moveDisks(stack<int> &source, stack<int> &dest, string &s, string &d)
{
    int topS, topD;
    if (source.empty())
    {
        topD = dest.top();
        dest.pop();
        source.push(topD);
        cout << "Disk " << topD << ":  " << d << " -> " << s << " \n";
    }
    else if (dest.empty())
    {
        topS = source.top();
        source.pop();
        dest.push(topS);
        cout << "Disk " << topS << ":  " << s << " -> " << d << " \n";
    }
    else if (source.top() > dest.top())
    {
        topD = dest.top();
        dest.pop();
        source.push(topD);
        cout << "Disk " << topD << ":  " << d << " -> " << s << " \n";
    }
    else
    {
        topS = source.top();
        source.pop();
        dest.push(topS);
        cout << "Disk " << topS << ":  " << s << " -> " << d << " \n";
    }
}

void TowerOfHanoi(int &disk, stack<int> &s, stack<int> &a, stack<int> &d)
{
    int i, moves = pow(2, disk) - 1;
    string so = "Source     ", au = "Auxiliary  ", de = "Destination";
    if (disk % 2 == 0)
    {
        string temp = de;
        de = au;
        au = temp;
    }
    for (i = disk; i > 0; i--)
        s.push(i);
    for (i = 1; i <= moves; i++)
    {
        if (i % 3 == 1)
            moveDisks(s, d, so, de);
        else if (i % 3 == 2)
            moveDisks(s, a, so, au);
        else
            moveDisks(a, d, au, de);
    }
}

int main()
{
    int disk;
    cout << "Enter no. of disks: "; cin >> disk;
    stack<int> s, a, d;
    TowerOfHanoi(disk, s, a, d);
    return 0;
}