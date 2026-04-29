#include <bits/stdc++.h>
using namespace std;

struct numberPair
{
    double value;
    double reciprocal;
};
void insertionSort (numberPair *pr, int n)
{
    for (int i=1; i<n; i++) {
        numberPair tmp = pr [i];
        int j = i-1;
        while (j>=0 and pr[j].reciprocal>tmp.reciprocal){
            pr[j+1] = pr[j];
            j--;
        }
        pr[j+1] = tmp;
    }
}
void bubbleSort (numberPair *pr, int n)
{
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (pr[j].reciprocal>pr[j+1].reciprocal)
                swap (pr[j+1], pr[j]);
        }
    }
}
void selectionSort (numberPair *pr, int n)
{
    for (int i=0; i<n-1; i++) {
        int tempIndex = i;
        for (int j=i; j<n; j++) {
            if (pr[i].reciprocal>pr[j].reciprocal) tempIndex = j;
        }
        numberPair temp = pr [i];
        pr [i] = pr [tempIndex];
        pr [tempIndex] = temp;
    }
}
int main ()
{
    int t; cin >> t;
    numberPair *arr = new numberPair[t];
    for (int i=0; i<t; i++)
    {
        float value; cin >> value;
        arr[i].value=value;
        arr[i].reciprocal = 0.1/value;


    }
    selectionSort(arr, t);
    cout << fixed << setprecision(2);
    for (int i=0; i<t; i++) (i==t-1)? cout << arr[i].value << endl : cout << arr[i].value << " ";

    return 0;
}

// 2.0, 0.5, 10.0, -4.0
