// sorted and distinct
#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int>st;
    st.insert(5);//O(lonN)
    st.insert(3);
    st.insert(4);
    st.insert(7);
    st.insert(4);
    st.insert(3);

    cout<<"Print set: ";//O(N)
    for(auto i: st)
    {
        cout<<i<<" ";
    }
    cout<<'\n';
    cout<<"Size: ";
    cout<<st.size()<<'\n';
    cout<<"Print enother way: ";
    for(auto it=st.begin(); it!=st.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<'\n';

    cout<<"Erase: 5\n";//O(lonN)
    st.erase(5);
    st.erase(100);

    cout<<"Print set after erase: ";//O(N)
    for(auto i: st)
    {
        cout<<i<<" ";
    }
    cout<<'\n';

    if(st.find(7) != st.end())//O(logN)
    {
        cout<<"7 found \n";
    }
    else 
    {
        cout<<"Not found\n";
    }

    return 0;
}