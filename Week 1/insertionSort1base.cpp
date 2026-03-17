#include <bits/stdc++.h>
using namespace std;

void printArray (int *a, int n)
{
    for (int i=1; i<=n; i++) {
        if (i==n) cout << a [i] << endl;
        else cout << a[i] << " ";
    }
}
void insertionSort1Base(int *arr, int n)
{

    for (int i=2; i<=n; i++) {
        int j = i-1;
        int temp = arr [i];

        while (j>=1 and arr[j]>temp) {
            arr [j+1] = arr [j];
            j--;
        }
        arr [j+1] = temp;
    }
}

int main ()
{
    int n; cin >> n;
    int arr [n+1];

    for (int i=1; i<=n; i++) cin >> arr[i];

    cout << "Before Sorting: ";
    printArray(arr, n);
    insertionSort1Base(arr, n);
    cout << "After sorting: ";
    printArray(arr,n);

    return 0;

}
