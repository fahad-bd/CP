#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);

    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    return 0;
}