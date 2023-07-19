#include<bits/stdc++.h>
using namespace std;
//key always sorted
int main()
{
    map<string, int>mp;
    mp["goru"]=1;//insert O(lonN)
    mp["cagol"]=2;
    mp["vera"]=3;
    mp["domba"]=3;
    cout<<mp["goru"]<<'\n';//O(logN)
    for(auto i:mp){//O(N)
        cout<<"Key: "<<i.first<<" , Vlaue: "<<i.second<<'\n';
    }

    cout<<"Size : "<<mp.size()<<'\n';//O(1);
    return 0;
}