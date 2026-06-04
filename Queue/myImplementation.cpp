#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
public:
    static constexpr int arraySize = 3;
    int arr[arraySize];
    int qfront = 0, rear = -1;
    int currentSize=0;

    void printQueue ()
    {
        int i;
        for (i=qfront; i!=rear; i=(1+i)%arraySize)
            cout << arr[i] << " ";
        cout << arr [i] << endl;
    }

    void push (int x)
    {
        if (currentSize==arraySize){
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear+1)%arraySize;
        arr[rear] = x;
        currentSize++;
    }
    int pop ()
    {
        if (currentSize==0) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int index = qfront;
        qfront = (qfront+1)%arraySize;
        return arr[index];
    }
};
int main ()
{
    CircularQueue Q1;

    Q1.push(1);
    Q1.push(2);
    Q1.push(3);
    Q1.push(4);
    cout<< Q1.pop() << endl;
    Q1.printQueue();


}
