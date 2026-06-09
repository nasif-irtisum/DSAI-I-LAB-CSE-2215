#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:

    static constexpr int sz = 5;
    int arr[sz];
    int top = -1;

    void push (int n)
    {
        if (top+1==sz) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top]=n;
    }
    int pop ()
    {
        if (top==-1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        top--;
        return arr [top+1];
    }
    void printStack ()
    {
        for (int i=0; i<=top; i++) {
            (i+1==top) ? cout << arr[i] << endl : cout << arr [i] << " ";
        }
    }
    bool isEmpty()
    {
        return top==-1;
    }
};
class Queue
{
public:

    Stack st1, st2;

    void enqueue (int x)
    {
        while (!st1.isEmpty()) {
            st2.push(st1.pop());
        }
        st1.push(x);
        while (!st2.isEmpty())
            st1.push (st2.pop());
    }
    void printQueue ()
    {
        for (int i=0; i<=st1.top; i++){
           (i==st1.top) ? cout << st1.arr[i] << endl : cout << st1.arr [i] << " ";
        }
    }
    int dequeue()
    {
        return st1.pop();
    }
};

int main ()
{
    Queue q;
    q.enqueue (1);
    q.enqueue (2);
    q.enqueue (3);
    cout <<q.st1.top << endl;
    q.printQueue();
    cout << q.dequeue() << endl;
    q.printQueue();
}
