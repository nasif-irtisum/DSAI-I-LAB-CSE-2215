#include <bits/stdc++.h>
using namespace std;

class Container
{
public:
    Container()
    {

    }
    string str;
    int len;
};

void insertionSort(Container *arr, int n)
{
    for (int i=1; i<n; i++) {
        Container temp = arr[i];
        int j=i-1;
        while (j>=0 and arr[j].len>temp.len) {
            arr [j+1] = arr[j];
            j--;
        }
        arr [j+1] = temp;
    }
}

void bubbleSort (Container *arr, int n)
{
    for (int i=0; i<n-1; i++) {
        bool flag = true;
        for (int j=0; j<n-i-1; j++){
            if (arr[j].len>arr[j+1].len) {
                swap (arr[j], arr[j+1]);
                flag = false;
            }
        }
        if (flag) break;
    }
}

int main ()
{
    int n; cin >> n;
    Container *arr = new Container[n];

    for (int i=0;i<n; i++) {
        string st; cin >> st;
        arr[i].str = st;
        arr[i].len=st.length();

    }
    //insertionSort(arr,n);
    bubbleSort(arr,n);

    for (int i=0;i<n;i++) cout << arr[i].str << (i==n-1? "\n":" ");

    return 0;
}
