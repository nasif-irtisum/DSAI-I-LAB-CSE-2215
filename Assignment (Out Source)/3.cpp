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
        cout << "Current: " << arr[top] << endl;
    }

    void pop(){
        top--;
        if(top==-1) {
            cout << "No Previous Page" << endl;
            return;
        }

        cout <<"Current: " << arr[top] << endl;


    }

    void printStack(){

        for(int i=0;i<=top;i++) cout<<arr[i]<<" ";

    }
};



int main(){
    Stack s1;

    int t; cin >> t;

    while (t--) {
        string msg; cin >> msg; getchar();

        if (msg == "BACK") s1.pop();
        if (msg=="VISIT") {
            string value; cin >> value; getchar();
            s1.push(value);
        }

    }

}
