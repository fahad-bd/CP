/*
node edge
7
8
1 2
1 3
2 4
3 4
3 5 
3 7
4 6
6 7
Created by Fahad Ahammed
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int level[100005];
int parent[100005];
int visited[100005];

void bfs(int root){
    queue<int> q;
    q.push(root);
    visited[root] = 1;
    parent[root] = -1;
    level[root] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<adj[u].size();i++){
            int v = adj[u][i];

            if(visited[v]==0){
                q.push(v);
                visited[v] = 1;
                parent[v] = u;
                level[v] = level[u]+1;
            }
        }
    }
}

int main() 
{
    int nodeSize, edgeNumber, a,b;
    cin>>nodeSize>>edgeNumber;

    for (int i = 0; i < edgeNumber; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    
    for(int i=0; i<nodeSize; i++) cout<<i<<' ';
    cout<<endl;

    for(int i=0; i<nodeSize; i++) cout<<visited[i]<<' ';
    cout<<endl;

    for(int i=0; i<nodeSize; i++) cout<<level[i]<<' ';
    cout<<endl;

    for(int i=0; i<nodeSize; i++) cout<<parent[i]<<' ';
    cout<<endl;
    return 0;
}