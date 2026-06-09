#include <iostream>
using namespace std;

class Queue {
public:
    static constexpr int arraySize=10;
    int first=0, rear = -1;
    int currentSize =0;
    int arr [arraySize];

    void printQueue()
    {
        int i;
        for (i=first; i!=rear; i=(i+1)%arraySize)
            cout << arr[i] << " ";
        cout << arr [i] << endl;
    }
    void enqueue(int n)
    {
        if (currentSize==arraySize) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear+1)%arraySize;
        arr[rear]=n;
        currentSize++;
    }
    int dequeue()
    {
        if (currentSize==0) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int index = first;
        first = (first+1)%arraySize;
        currentSize--;
        return arr[index];
    }
    int queueFront ()
    {
        if (currentSize==0) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        return arr[first];
    }
    bool isEmpty()
    {
        return currentSize==0;
    }
};

class StackWithQueue {
public:
    Queue q1;
    Queue q2;

    void push (int x)
    {
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        q1.enqueue(x);

        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
    }

    int pop ()
    {
        return q1.dequeue();
    }
    int top()
    {
        return q1.queueFront();
    }
    bool isEmpty ()
    {
        return q1.isEmpty();
    }
    void display ()
    {
        q1.printQueue();
    }
    int stackSize ()
    {
        return q1.currentSize;
    }
};

void convertToBinary(int n) {

    StackWithQueue st;

    while(n!=0) {
        st.push(n%2);
        n/=2;
    }

    cout << "Binary: ";
    while(!st.isEmpty()) cout <<st.pop();

    cout << endl;
}

void sortUsingStack(int arr[], int n) {

    StackWithQueue st, temp;

    for (int i=0; i<n; i++) st.push(arr[i]);

    while (!st.isEmpty()){
        int tempVar = st.pop();

        while (!temp.isEmpty() and temp.top()<tempVar) {
            st.push(temp.pop());
        }
        temp.push(tempVar);
    }
    for (int i=0; i<n; i++) arr[i]=temp.pop();

    //st.display();
}

void printArray(int arr[], int n){
    cout << "Sorted Array: ";
    for (int i=0; i<n; i++) {
        (i==n-1) ? cout << arr[i] << endl : cout << arr [i] << " ";
    }
}

int main() {
    int decimalNumber;
    int n;

    StackWithQueue SQ;
    /*
    Queue Q1;

    Q1.enqueue(1);
    Q1.enqueue(2);
    Q1.enqueue(3);
    Q1.enqueue(4);
    Q1.dequeue();
    Q1.printQueue();
    cout << Q1.currentSize << endl;

    StackWithQueue S;
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(40);
    S.push(50);
    cout << S.stackSize() << endl;
    cout << S.isEmpty() << endl;
    S.display();*/

    cin >> decimalNumber;
    convertToBinary(decimalNumber);

    cin >> n;
    int arr[n];


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortUsingStack(arr, n);
    printArray(arr,n);


    return 0;
}
