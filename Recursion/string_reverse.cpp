#include <bits/stdc++.h>
using namespace std;

void stringRev (char *str, int i, int j)
{
    if (i>j) return;

    swap(str[i], str[j]);

    stringRev(str, i+1, j-1);
}
int main ()
{
    char str [1000];
    cin>> str;
    stringRev(str, 0, strlen(str)-1);
    cout << str << endl;


    return 0;
}
