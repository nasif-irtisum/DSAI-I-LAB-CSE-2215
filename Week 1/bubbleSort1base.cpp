#include <bits/stdc++.h>
using namespace std;

void printArray (int *arr, int n)
{
    for (int i=1; i<=n; i++) {
        if (i==n) cout << arr[i] << endl;
        else cout << arr [i] << " ";
    }
}

void bubbleSort1Base(int *arr, int n)
{
    for (int i=1; i<=n-1; i++) {
        for (int j=1; j<=n-i; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr [j];
                arr [j] = arr [j+1];
                arr [j+1] = temp;
            }
        }
    }
}

int main ()
{
    int n; cin >> n;
    int arr[n+1];

    for (int i=1; i<=n; i++) cin >> arr [i];

    cout << "Before Sorting: ";
    printArray(arr, n);

    bubbleSort1Base(arr, n);

    cout << "After Sorting: ";
    printArray(arr, n);

    return 0;
}
