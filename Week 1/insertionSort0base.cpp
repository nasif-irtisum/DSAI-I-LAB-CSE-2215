#include <bits/stdc++.h>
using namespace std;

void printArray (int *a, int n)
{
    for (int i=0; i<n; i++) {
        if (i==n-1) cout << a [i] << endl;
        else cout << a[i] << " ";
    }
}
void insertionSort0Base(int *arr, int n)
{

    for (int i=1; i<n; i++) {
        int j = i-1;
        int temp = arr [i];

        while (j>=0 and arr[j]>temp) {
            arr [j+1] = arr [j];
            j--;
        }
        arr [j+1] = temp;
    }
}

int main ()
{
    int n; cin >> n;
    int arr [n];

    for (int i=0; i<n; i++) cin >> arr[i];

    cout << "Before Sorting: ";
    printArray(arr, n);
    insertionSort0Base(arr, n);
    cout << "After sorting: ";
    printArray(arr,n);

    return 0;

}
