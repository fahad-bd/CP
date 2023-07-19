#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 2e5;

vector<int>adj_list[N];
int level[N];
int visited[N];

void bfs(int nodes)
{
    queue<int>q;
    q.push(nodes);
    
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        
        for(auto i: adj_list[t])
        {
            if(visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
                level[i] = level[t]+1;
            }
        }
    }
}

int main()
{
    
    int u,v;
    int nodes, edges;
    cin>>nodes>>edges;
    
    for(int i=0 ; i<edges ; i++)
    {
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    level[0] = 0;
    visited[0] = 1;
    int src = 0;
    bfs(0);
    
    for(int i=0 ; i<nodes; i++)
    {
        cout<<"node "<<i<<" ->"<<"level :"<<level[i]<<endl;
    }
    return 0;
}