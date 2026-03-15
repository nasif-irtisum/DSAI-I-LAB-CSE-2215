#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i=0; i<n; i++) {
        if (i==n-1) cout << arr[i] << endl;
        else cout << arr [i] << " ";
    }
}

void selectionSort1base(int *arr, int n)
{
    for (int i=0; i<n-1; i++){
        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j]<arr[minIndex]) minIndex=j;
        }
        swap(arr[minIndex], arr[i]);
    }
}
int main ()
{
    int n; cin >> n;
    int arr [n];

    for (int i=0; i<n; i++) cin >> arr[i];

    cout << "Before Sorting: ";
    printArray(arr,n);

    selectionSort1base(arr, n);

    cout << "After Sorting: ";
    printArray (arr,n);

    return 0;
}
