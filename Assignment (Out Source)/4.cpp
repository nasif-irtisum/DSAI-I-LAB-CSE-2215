#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    int top = -1;
    int size = 20;
    string arr[20];

    void push(string value){
        if(top==size-1) return;
        top++;
        arr[top]=value;
    }

    string pop(){
        if(top==-1) {
            return NULL;
        }

        string tp = arr[top];
        top--;
        return tp;


    }

    void printStack(){

        for(int i=0;i<=top;i++) cout<<arr[i]<<" ";

    }
};



int main(){
    Stack s1;

    int t; cin >> t;
    int t2 = t;
    while (t--) {
        string value;
        cin >> value;
        s1.push (value);
    }
    cout << "Original: ";
    s1.printStack(); cout << endl;

    cout << "Reversed: ";
    while (t2--) cout << s1.pop () << " ";

    cout << endl;
}
