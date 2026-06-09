#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:

    static constexpr int sz = 5;
    int arr [5];
    int currentSize=0, first =0, rear=-1;

    void enqueue (int x)
    {
        if (currentSize==sz) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear=(rear+1)%sz;
        currentSize++;
        arr[rear]=x;
    }

    void printQueue()
    {
        int i;
        for (i= first; i!=rear; i=(i+1)%sz)
            cout << arr[i] << " ";
        cout << arr [i] << endl;
    }

    int dequeue()
    {
        if (currentSize==0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int x = arr[first];
        first = (first+1)%sz;
        currentSize--;
        return x;
    }

};

int main ()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    q.printQueue();
    cout << q.dequeue() << endl;
    q.printQueue();
    cout << "Queue Size: " << q.currentSize << endl;
    q.enqueue(1);
    q.printQueue();
}
