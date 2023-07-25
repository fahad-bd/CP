#include<bits/stdc++.h>
using namespace std;

int power(int n, int k, int ans)
{
    if(k==0) return ans;
    ans = ans*n;
    return power(n,k-1,ans);
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<power(n,m,1)<<'\n';
    return 0;
}