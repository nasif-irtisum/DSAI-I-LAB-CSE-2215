#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:

    static constexpr int sz = 10;
    int arr [sz];
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
        if (rear==-1 or currentSize==0) {
            cout << "Queue is empty!" << endl;
            return;
        }
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
    int t; cin >> t;
    Queue q; q.enqueue(1);

    while(t--){
        int x = q.dequeue();

        cout<<x<<" ";
        int n1 = x*10;
        int n2 = x*10+1;

        q.enqueue(n1);
        q.enqueue(n2);
    }
}
