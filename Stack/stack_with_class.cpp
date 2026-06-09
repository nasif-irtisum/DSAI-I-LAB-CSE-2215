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
};
int main ()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.printStack();
    st.push(3);
    st.printStack();
    cout << st.pop() << endl;
    st.printStack();
}
