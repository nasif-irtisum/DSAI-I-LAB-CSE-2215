#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:

    static constexpr int sz=10;
    char arr[sz];
    int top=-1;

    void push (char c)
    {
        if (top+1==sz) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = c;
    }
    char pop ()
    {
        if (top==-1) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        top--;
        return arr[top+1];
    }

    bool isEmpty ()
    {
        return top==-1;
    }
};

int main ()
{
    string s; cin >> s;
    Stack st;
    for (int i=0; i<s.size(); i++)  st.push(s[i]);

    while (!st.isEmpty()) cout << st.pop();

    cout << "\n";
}
