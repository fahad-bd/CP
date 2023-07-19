#include<bits/stdc++.h>
using namespace std;

// time O(n) space O(n)

int factrul(int n)
{
    if(n==1) return 1;

    return n*factrul(n-1);
}

int main()
{
    int n=4;
    cout<<factrul(n)<<endl;
    return 0;
}