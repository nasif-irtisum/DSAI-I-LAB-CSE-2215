#include <bits/stdc++.h>
using namespace std;

void printArray (int *arr, int n)
{
    for (int i=0; i<n; i++) {
        if (i==n-1) cout << arr [i] << endl;
        else cout << arr [i] << " ";
    }
}

void bubbleSort0Base(int *arr, int n)
{
    for (int i=0; i<n-1; i++) {
        bool isSwap = true;
        for (int j=0; j<n-1-i; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr [j];
                arr[j] = arr [j+1];
                arr[j+1] = temp;
                isSwap = false;
            }
        }
        if (isSwap) break;
    }
}
int main ()
{
    int n; cin >> n;
    int arr [n];

    for (int i=0; i<n; i++) cin >> arr[i];

    cout << "Before Sorting: ";
    printArray(arr, n);

    bubbleSort0Base(arr, n);

    cout << "After Sorting: ";
    printArray(arr, n);

    return 0;


}
