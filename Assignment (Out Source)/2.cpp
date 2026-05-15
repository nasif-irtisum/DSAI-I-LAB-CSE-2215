#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    int top = -1;
    int size = 20;
    char arr[20];

    void push(char value){
        if(top==size-1) return;
        top++;
        arr[top]=value;
    }

    char pop(){
        if(top==-1) return '\0';
        char valueAtTop = arr[top];
        top--;
        return valueAtTop;
    }

    void printStack(){

        for(int i=0;i<=top;i++) cout<<arr[i]<<" ";

    }
};



int main(){
    Stack s1;

    char str [20];
    gets(str);

    int flag = 1;
    for(int i=0; str[i]!='\0' ; i++){
        char value = str[i];

        if(value=='(' || value=='{' || value=='[') s1.push(value);
        else if(value==')' || value==']' || value=='}'){
            char poppedClosingBracket = s1.pop();
            if(value==')'  && poppedClosingBracket=='('){

            }else if (value=='}'  && poppedClosingBracket=='{'){

            }else if (value==']'  && poppedClosingBracket=='['){

            }else{

                flag=0;
                break;
            }
        }else{

        }
    }


    if(s1.top!=-1){
        flag=0;
    }


    if(flag==1){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced"<<endl;
    }
}
