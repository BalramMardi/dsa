#include <iostream>
using namespace std;

#define n 100

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "QUEUE OVERFLOW" << endl;
            return;
        }
        back++;
        arr[back] = x;

        if (front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if (front == -1 or front > back)
        {
            cout << "no element" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 or front > back)
        {
            cout << "no element" << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 or front > back)
        {

            return true;
        }
        return false;
    }
};

int main()
{

    queue q;
    for (int i = 1; i < 5; ++i)
    {
        q.push(i);
    }

    cout << q.peek() << endl;
    q.pop();

    cout << q.empty() << endl;

    while (!q.empty())
    {
        cout << q.peek() << endl;
        q.pop();
    }
}