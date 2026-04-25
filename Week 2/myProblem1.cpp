#include <bits/stdc++.h>
using namespace std;
class Container
{
public:
    Container()
    {

    }
    int id;
    string name;
};

void insertionSort (Container *a, int n)
{
    for (int i=1; i<n; i++) {
        Container temp = a[i];
        int j= i-1;

        while (j>=0 and a[j].name[0] >temp.name[0]) {
           a[j+1] = a[j];
           j--;
        }
        while (j>=0 and a[j].name[0]==temp.name[0]) {
            if (a[j].id> temp.id) {
                a [j+1] = a[j];
                j--;
            }
        }
        a[j+1] = temp;
    }
}
using namespace std;
int main()
{
    int n; cin >> n;
    Container *st = new Container [n];

    for (int i=0; i<n; i++) cin >> st[i].name >> st[i].id;

    insertionSort(st, n);

    for (int i=0; i<n; i++) cout << st[i].name << " " << st[i].id << endl;
}
