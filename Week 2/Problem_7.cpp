#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n)
{
    for (int i=0; i<n-1; i++) {
        int mn = i;
        for (int j=i+1; j<n; j++) {
            if (arr[mn]>arr[j]) mn = j;
        }
        swap(arr[mn], arr[i]);
    }
}
int main ()
{
    int n; cin>>n;
    int arr [n];
    for (int i=0;i<n; i++) cin >> arr [i];

    selectionSort(arr,n);
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    int mxSequence = 1, cnt=0;

    for (int i=0; i<n-1; i++) {
        if (arr[i+1]-arr[i]==1) {
            cnt++;
            if (cnt>mxSequence) mxSequence=cnt;
        }
        else cnt= 0;
    }
    cout << mxSequence << endl;

    return 0;

}
