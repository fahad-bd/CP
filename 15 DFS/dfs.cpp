#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];

vector<int>adj_list[N];

void dfs(int node)
{
    cout<<node<<endl;
    visited[node] = 1;

    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }
}

/*
intput:
6 6

0 1
1 2
2 3
1 5
2 4 
5 4
*/

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    int u,v;

    for(int i=0; i<edges; i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 0;
    dfs(src);

    return 0;
}