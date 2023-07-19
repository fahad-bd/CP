#include<bits/stdc++.h>
using namespace std;

void fun(int i, int sum)
{
    if(i<1)
    {
        cout<<sum<<endl;
        return;
    }

    fun(i-1, sum+i);
}

int main()
{
    int n;
    n=10;
    fun(n,0);
    return 0;
}