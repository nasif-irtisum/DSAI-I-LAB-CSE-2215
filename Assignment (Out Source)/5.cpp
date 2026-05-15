#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    int top = -1;
    int size = 20;
    int arr[20];

    void push(char value){
        if(top==size-1) return;
        top++;
        arr[top]=value;
    }

    int pop(){
        if(top==-1) return 0;
        char valueAtTop = arr[top];
        top--;
        return valueAtTop;
    }

    void printStack(){

        for(int i=0;i<=top;i++) cout<<arr[i]<<" ";

    }
};



int main(){
    Stack st;

    char str [20];
    gets(str);

    for (int i=0; str[i]!= '\0'; i++) {
        if (str [i]== '+') {
            int val1= st.pop();
            int val2 = st.pop();
            st.push(val1+val2);
        }
        else if (str [i]== '-') {
            int val1= st.pop();
            int val2 = st.pop();
            st.push(val1-val2);
        }
        else if (str [i]== '*') {
            int val1= st.pop();
            int val2 = st.pop();
            st.push(val1*val2);
        }
        else if (str [i]== '/') {
            int val1= st.pop();
            int val2 = st.pop();
            if (val2==0) {
                cout << "Error: division by zero";
                break;
            }
            st.push(val1/val2);
        }
        else if (str[i]== ' ') continue;

        else {
            int val = str[i] - '0';
            st.push (val);
        }
    }

    cout << "Result: " << st.pop();
}
