/*
5 8
########
#..#...#
#.##.#.#
.#.#...#
#.######
Rooms - 5
Length of the longest room - 8

floor = .
wall = #
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
char Map[N][N];
int visited[N][N];

int n,m;

int is_valid_move(int r, int c)
{
    if(r>=0 && r<n && c>=0 && c<m && Map[r][c]=='.')
    {
        return 1;
    }
    return -1;
}

int bfs(int r, int c)
{
    queue< pair<int,int> > q;
    q.push({r,c});
    visited[r][c] = 1;
    
    int room_size = 0;
    
    while(!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        
        room_size++;
        
        int r = curr.first;
        int c = curr.second;
        
        
        int a = is_valid_move(r+1, c);
        int b = is_valid_move(r-1, c);
        int c1 = is_valid_move(r, c+1);
        int d = is_valid_move(r, c-1);
        
        if(a==1 && visited[r+1][c] == 0)
        {
            q.push({r+1,c});
            visited[r+1][c] = 1;
        }
        if(b==1 && visited[r-1][c] == 0)
        {
            q.push({r-1,c});
            visited[r-1][c] = 1;
        }
        if(c1==1 && visited[r][c+1] == 0)
        {
            q.push({r,c+1});
            visited[r][c+1] = 1;
        }
        if(d==1 && visited[r][c-1] == 0)
        {
            q.push({r,c-1});
            visited[r][c-1] = 1;
        }
    }
    
    return room_size;
}

int main()
{
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>Map[i][j];
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            visited[i][j] = 0;
        }
    }
    
    int number_of_room = 0;
    int longest_room = 0;
    int room_size = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visited[i][j]==0 && Map[i][j]=='.')
            {
                room_size = bfs(i, j);
                number_of_room++;
                longest_room = max(longest_room, room_size);
            }
        }
    }
    
    cout<<"Rooms - "<<number_of_room<<'\n';
    cout<<"Length of the longest room - "<<longest_room;
    
    return 0;
}
