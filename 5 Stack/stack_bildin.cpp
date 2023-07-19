#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Stack
    stack<int> st;

    //push
    st.push(10);
    st.push(20);
    st.push(30);

    //size
    cout<<"Stack size: "<<st.size()<<'\n';

    //top
    cout<<st.top()<<'\n';

    //pop
    st.pop();
    cout<<st.top()<<'\n';
    st.pop();
    cout<<st.top()<<'\n';
    st.pop();
    
    return 0;
}