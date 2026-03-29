#include <bits/stdc++.h>
using namespace std;

void insertionSortDescending(int *arr, int n)
{
    for (int i=1; i<n; i++) {
        int temp = arr [i];
        int j= i-1;
        while (j>=0 and arr[j]<temp) {
            arr [j+1] = arr [j];
            j--;
        }
        arr [j+1] = temp;
    }
}
void bubbleSortAscending (int *arr, int n)
{
    for (int i=0; i<n-1; i++) {
        bool flag = true;
        for (int j=0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]) {
                int temp = arr [j];
                arr [j] = arr [j+1];
                arr [j+1] = temp;
                flag = false;
            }
        }
        if (flag) break;
    }
}
int main ()
{
    int n; cin >> n;
    int arr [n];
    for (int i=0;i<n; i++) cin >> arr [i];

    int evenArraysize, oddArraySize;

    if(n%2==0) {
        evenArraysize = oddArraySize = n/2;
    }
    else {
        evenArraysize = n/2+1;
        oddArraySize = n/2;
    }

    int evenArr [evenArraysize], oddArr[oddArraySize];

    for (int i=0,j=0; i<n; i+=2, j++) evenArr[j] = arr[i];

    for (int i=1, j=0; i<n; i+=2, j++) oddArr[j] = arr[i];

    bubbleSortAscending(evenArr, evenArraysize);
    insertionSortDescending(oddArr, oddArraySize);

    for (int i=0, j=0; i<n; i+=2, j++) arr[i] = evenArr[j];
    for (int i=1, j=0; i<n; i+=2, j++) arr[i]=oddArr[j];

    for (int i=0; i<n; i++) cout << arr[i] << (i==n-1? "\n":" ");

    return 0;
}
