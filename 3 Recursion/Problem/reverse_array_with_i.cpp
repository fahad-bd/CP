#include<bits/stdc++.h>
using namespace std;

int n=5;
int arr[]={1,2,3,4,5};

void reverse(int i)
{
    if(i>=n/2) return;

    swap(arr[i], arr[n-i-1]);

    reverse(i+1);
}

int main()
{
    reverse(0);

    for(auto i: arr) cout<<i<<" ";
    return 0;
}