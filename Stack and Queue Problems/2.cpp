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

    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(' or s[i] == '{' or s[i]=='[')
            st.push(s[i]);

        else {
            char value = st.pop();
            if (s[i]==')' and value !='(') {
                cout << "Incorrect" << endl;
                return 0;
            }
            else if (s[i]=='}' and value !='{') {
                cout << "Incorrect" << endl;
                return 0;
            }
            else if (s[i]==']' and value !='[') {
                cout << "Incorrect" << endl;
                return 0;
            }
        }
    }
    cout << "Correct" << endl;
    return 0;
}
