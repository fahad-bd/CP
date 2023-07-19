//sorted but not distant
#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int>ms;
    ms.insert(3);//O(ligN)
    ms.insert(1);
    ms.insert(7);
    ms.insert(7);
    ms.insert(7);
    ms.insert(4);
    ms.insert(3);

    for(auto it: ms)cout<<it<<" "; //O(N)
    cout<<'\n';
    cout<<"Size: ";//O(1)
    cout<<ms.size()<<'\n';

    //erase all occurrence
    ms.erase(3);//O(logN)

    cout<<"After erase all occurrence of 3: ";
    for(auto it: ms)cout<<it<<" "; //O(N)
    cout<<'\n';

    //erase a single occurrence
    ms.erase(ms.find(7));
    cout<<"After erase 7 single occurrence: ";
    for(auto it: ms)cout<<it<<" "; //O(N)
    cout<<'\n';

    //find O(lonN)
    if(ms.find(5)!=ms.end())
    {
        cout<<"5 exists\n";
    }
    else cout<<"5 not exists\n";
    return 0;
}