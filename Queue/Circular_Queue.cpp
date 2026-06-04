#include <bits/stdc++.h>
using namespace std;

class circularQueue
{
    int *arr;
    int crntSize=0, capacity;
    int fr, rear;

public:
    circularQueue(int sz)
    {
        capacity=sz;
        arr = new int [sz];
        fr=0, rear=-1;
    }
    void push (int data)
    {
        if (crntSize==capacity){
            cout << "Circular Queue is Full" << endl;
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear] = data;
        crntSize++;
    }
    int pop()
    {
        if (isEmpty()){
            cout << "Circular Queue is Empty" << endl;
            return -1;
        }
        int index = fr;
        fr = (fr+1)%capacity;
        crntSize--;
        return arr[index];

    }
    int queueFront()
    {
        if (isEmpty()){
            cout << "Circular Queue is Empty" << endl;
            return -1;
        }
        return arr [fr];
    }
    bool isEmpty()
    {
        return crntSize==0;
    }
    void printQueue ()
    {
        int i;
        for (i=fr; i!=rear; i=(i+1)%capacity) {
            cout << arr[i] << " ";
        }
        cout << arr [i] << endl;
    }
};

int main ()
{
    circularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cout << cq.pop() << endl;
    cout << cq.pop() << endl;
    cq.push(1);
    cq.push(2);
    cq.printQueue();


}
