#include <bits/stdc++.h>
using namespace std;

int const sz = 5;
int arr[sz];
int top = -1;

void push (int n)
{
    if (top+1==sz) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    top++;
    arr[top] = n;
}
int pop ()
{
    if (top==-1) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    int x = arr [top];
    top--;
    return x;
}
void printStack ()
{
    for (int i=0; i<=top; i++) {
        (i+1==sz) ? cout << arr[i] << endl : cout << arr [i] << " ";
    }
}

int main ()
{
    for (int i=1; i<=10; i++) push(i);
    printStack();
    cout << "Pop: " << pop() << endl;
    printStack();
}
