#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int n)
{
    for (int i=1; i<n; i++){
        int temp = arr [i];
        int j= i-1;

        while (j>=0 and arr[j]>temp) {
            arr [j+1] = arr [j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main ()
{
    int n; cin >> n;
    int arr [n];
    for (int i=0;i<n;i++) cin>> arr [i];

    insertionSort(arr, n);

    //for (int i=0; i<n; i++) cout << arr [i] << (i==n-1? "\n":" ");

    int mn = INT_MAX;

    for (int i=0; i<n-1; i++){
        if (mn > arr [i+1]-arr[i]) mn = arr [i+1]- arr [i];
    }

    cout << mn << endl;


    return 0;

}
