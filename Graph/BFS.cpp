#include <bits/stdc++.h>
using namespace std;

const int WHITE=1, GRAY=2, BLACK =3;
int dist[100], parent[100], color[100];

void vertexAttributes (int v);
void getRoot (int n);

void printVector (vector <vector <int>> adList)
{
    cout << "*****************" << endl;
    for (int i=0; i<adList.size(); i++) {
        vector <int> v = adList[i];
        for (int j=0; j<v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
}

void BFS (vector <vector <int>> adjList, int source, int v, int e)
{
    for (int i=0; i<v; i++) {
        dist [i] = INT_MAX;
        color [i] = WHITE;
        parent[i]= -1;
    }
    queue<int>q;
    dist[source]=0;
    color[source]=GRAY;
    //source[parent]=-1;
    q.push(source);

    while (!q.empty()) {
        int vertex = q.front();
        color [vertex]=BLACK;
        q.pop();

        for (auto data : adjList[vertex]) {
            if (color[data]==WHITE) {
                color[data]=GRAY;
                dist[data]= dist[vertex]+1;
                parent [data] = vertex;
                q.push(data);
            }
        }
    }
}


int main ()
{
    vector <vector <int>> adjList;

    int v, e; cin >> v >> e;

    for (int i=0; i<v; i++) {
        vector <int> smallContainer;
        adjList.push_back(smallContainer);
    }
    for (int i=0; i<e; i++) {
        int a,b; cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back (a);
    }
    printVector(adjList);
    BFS(adjList, 0, v, e);
    vertexAttributes(v);

    for (int i=0; i<v; i++) {
        getRoot(i);
        cout << endl;
    }

    return 0;
}


void vertexAttributes (int v)
{
    for (int i=0; i<v; i++) {
        cout << "Vertex: " << i << " | " << "Parent: " << parent[i] << " | ";
        cout << "Distance: " << dist[i] << " | " << "Color: " << color[i] << endl;;

    }
}
void getRoot (int n)
{
    if (n==-1)return;
    getRoot(parent[n]);
    cout << "->" << n;
}
