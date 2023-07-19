#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes = 4;
    vector< vector<int> > edgeList;
    edgeList.push_back({0,1});
    edgeList.push_back({1,2});
    edgeList.push_back({1,3});
    edgeList.push_back({2,3});

    for(int i=0;i<edgeList.size();i++)
    {
        cout<<edgeList[i][0]<<" "<<edgeList[i][1]<<'\n';
    }
    return 0;
}