#include <bits/stdc++.h>
using namespace std;

class Number
{
public:
    Number()
    {

    }

    int realValue;
    int absoluteVale;
};

void insertionSort (Number *arr, int n)
{
    for (int i=1; i<n; i++) {
        Number temp = arr [i];
        int j= i-1;

        while (j>=0 and arr[j].absoluteVale>temp.absoluteVale) {
            arr[j+1] = arr [j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int main ()
{
    int n; cin >> n;
    Number *arr = new Number[n];

    for (int i=0; i<n; i++) {
        int num; cin >> num;
        arr[i].realValue = num;
        if (num<0) arr[i].absoluteVale = num*-1;
        else arr[i].absoluteVale = num;
    }

    insertionSort(arr, n);

    for (int i=0; i<n; i++){
        cout << arr[i].realValue << (i==n-1? "\n":" ");
    }
    return 0;
}
