#include<bits/stdc++.h>
using namespace std;

void fun(int i, int n)
{
    if(i<1) return;

    fun(i-1, n);

    cout<<i<<" ";
}

int main()
{
    int n;
    n=10;

    fun(n,n);
    return 0;
}