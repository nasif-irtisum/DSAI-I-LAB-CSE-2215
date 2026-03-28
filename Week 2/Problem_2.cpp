#include <bits/stdc++.h>
using namespace std;
void selectionSort (int *arr, int n)
{
    for (int i=0; i<n-1; i++) {
        int mn = i;
        for (int j=i+1; j<n; j++) {
            if (arr [j] < arr [mn]) mn = j;
        }
        swap (arr [mn], arr [i]);
    }
}
int main ()
{
    int n; cin >> n;
    int arr [n];
    for (int i=0; i<n; i++) cin >> arr [i];

    selectionSort(arr, n);

    //for (int i=0; i<n; i++) cout << arr[i] << ((i==n-1)? "\n":" ");

    if (n%2!=0) cout << arr [n/2] << endl;
    else cout << (arr [n/2]+arr[n/2 - 1])/2 << endl;

    return 0;
}
