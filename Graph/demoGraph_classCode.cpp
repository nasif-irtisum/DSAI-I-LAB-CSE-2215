#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int WHITE = 1;
int GRAY = 2;
int BLACK = 3;

void printAdjList(  vector <vector <int>>   adjList){
    cout<<"********************************"<<endl;
    for(int i=0;i<adjList.size();i++){
        vector <int > smallContainer  = adjList[i];
        for(int j=0;j<smallContainer.size();j++){
            cout<<smallContainer[j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n********************************"<<endl;

}

int dist[100];
int parent[100];
int color[100];

void printVertexProperties(int V, int E){
    for(int i=0;i<V;i++){
        cout<<"parent="<<parent[i]<<"color="<<color[i]<<"distance="<<dist[i]<<endl;
    }

}

void BFS(vector <vector <int>>   adjList, int source, int V, int E){
    for(int i=0;i<=V-1;i++){
        dist[i]=9999;
        parent[i] = -1;
        color[i]=WHITE;
    }

    dist[source]=0;
    parent[source]=-1;
    color[source]=GRAY;
    queue <int> Q;

    Q.push(source);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int v:adjList[u]){
            if(color[v]==WHITE){
                color[v]=GRAY;
                dist[v] = dist[u]+1;
                parent[v]=u;
                Q.push(v);
            }
        }

        color[u]=BLACK;
    }


}

void printPath(int v){
    if(v==-1){
        return ;
    }

    printPath(parent[v]);
    cout<<"->"<<v;
}

int main(){
    vector  < vector<int> > adjList;

    int V,E;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    cout<<"Enter the number of edges"<<endl;
    cin>>E;

    for(int i=1;i<=V;i++){
        vector <int> smallContainer;
        adjList.push_back(smallContainer);
    }

    cout<<"Enter the edges"<<endl;
    for(int i=1;i<=E;i++){
        int u,v;
        cin>>u;
        cin>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    printAdjList(adjList);

    BFS(adjList,0,V,E);

    printVertexProperties(V,E);

    cout<<"All the paths from the source"<<endl;
    for(int i=0;i<V;i++){
        printPath(i);
        cout<<endl;
    }
    return 0;
}
/*
6
7
0 1
2 0
1 2
1 5
5 2
2 4
2 3
*/
