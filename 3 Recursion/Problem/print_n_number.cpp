#include<bits/stdc++.h>
using namespace std;
// big O(N) and space complexity O(N)
void fun(int i, int n)
{
    if(i>n) return ;
    cout<<i<<" ";
    fun(i+1,n); 
}

int main()
{
    int n;
    n=10;
    fun(1,n);
    return 0;
}