#include <bits/stdc++.h>
using namespace std;

void printVector (vector <vector <int>> adList)
{
    for (int i=0; i<adList.size(); i++) {
        vector <int> v = adList[i];
        for (int j=0; j<v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
}
int main ()
{
    vector <vector <int>> adjList;

    int v, e; cin >> v >> e;

    for (int i=0; i<v; i++) {
        vector <int> smallContainer;
        v.push_back(smallContainer);
    }
    for (int i=0; i<e; i++) {
        int a,b; cin >> a >> b;
        adjList[u].push_back(v);
        adjList[v].push_back (u);
    }
}
