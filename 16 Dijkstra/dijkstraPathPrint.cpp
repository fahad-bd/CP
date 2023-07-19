/*
Input:
10 10
1 4 201
2 3 238
3 4 40
3 6 231
3 8 45
4 5 227
4 6 58
4 9 55
5 7 14
6 10 242

Output:
1 4 6 10

source: 1 
destination: n
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

const int INF = 1e7;

vector< pair<int, int> >adj_list[N];

int Distance[N], visited[N];
int parent[N];

int nodes, edges;
    
void dijkstra(int src)
{
    for(int i=1; i<=nodes; i++)
    {
        Distance[i] = INF;
    }
    Distance[src] = 0;
    parent[src] = -1;
    
    for(int i=0; i<nodes; i++)
    {
        int selected_node = -1;
        for(int j=1; j<=nodes; j++)
        {
            if(visited[j] == 1)continue;
            if(selected_node == -1 || Distance[selected_node] > Distance[j])
            {
                selected_node = j;
            }
        }
        visited[selected_node] = 1;
        
        for(auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;
            
            if(Distance[selected_node] + edge_cst < Distance[adj_node])
            {
                Distance[adj_node] = Distance[selected_node] + edge_cst;
                parent[adj_node] = selected_node;
            }
        }
    }
}

int main() {
    cin>>nodes>>edges;
    
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    
    int src = 1;
    dijkstra(src);
    
    if(Distance[nodes] == INF)
    {
        cout<<-1<<'\n';
    }
    else
    {
        vector<int> path;
        path.push_back(nodes);
        int p = parent[nodes];
        while(true)
        {
            //cout<<p<<" ";
            path.push_back(p);
            p = parent[p];
            
            if(p == -1)
            {
                break;
            }
        }
        reverse(path.begin(), path.end());
        for(int i: path)
        {
            cout<<i<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
