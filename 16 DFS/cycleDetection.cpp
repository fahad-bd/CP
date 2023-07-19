#include <iostream>
#include <queue>
using namespace std;

/*
Cycle Detection in Directed Graph
https://cses.fi/problemset/task/1678

Input:
4 5
1 3
2 1
2 4
3 2
3 4

Output:
4
2 1 3 2
*/

const int N = 2e5;

vector<int>adj_list[N];
int visited[N];

bool dfs(int node)
{
    visited[node] = 1;
    
    for(int adj_node : adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            bool got_cycle = dfs(adj_node);
            if(got_cycle) return true;
        }
        else if(visited[adj_node] == 1)
        {
            return true;
        }
    }
    visited[node] = 2;
    
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    int u, v;
    
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    
    bool cycle_exists = false;
    
    for(int i = 1 ; i <= n ; i++)
    {
        if(visited[i] == 0)
        {
            bool got_cycle = dfs(i);
            if(got_cycle)
            {
                cycle_exists = true;
                break;
            }
        }
    }
    
    if(cycle_exists) cout<<"Cycle Exists\n";
    else cout<<"IMPOSIBLE\n";

    return 0;
}