#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];
int level[N];

vector<int>adj_list[N];

void bfs(int src)
{
    queue<int> q;

    visited[src] = 1;
    level[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for(int adj_node: adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head]+1;
                q.push(adj_node);
            }
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

    bfs(0);

    for(int i=0; i<nodes; i++)
    {
        cout<<"Node "<<i<<" -> level: "<<level[i]<<endl;
    }

    return 0;
}