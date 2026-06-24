#include <bits/stdc++.h>
using namespace std;
int WHITE =1, GRAY = 2, BLACK =3;
int color [100] = {WHITE};
int d_time[100] = {0}, f_time = {0};

void printList (vector <vector <int>> adjList)
{
    cout << "****************************" << endl;
    for (int i=0; i<adjList.size(); i++) {
        //vector <int> smContainer = adjList[i];
        for (int j=0; j<adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}
int main ()
{
    vector < vector <int>> adjList;
    int v, e; cin >> v >> e;

    for (int i=0;i<v; i++) {
        vector <int> shortContainer;
        adjList.push_back(shortContainer);
    }
    for (int i=0; i<e; i++) {
        int a, b; cin >> a >> b;
        adjList[a].push_back(b);
    }
    printList(adjList);
}
