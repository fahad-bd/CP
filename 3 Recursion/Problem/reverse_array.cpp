#include<bits/stdc++.h>
using namespace std;

int n=5;
int arr[]={1,2,3,4,5};

void reverse(int i, int r)
{
    if(i>=r)
    {
        return;
    }

    swap(arr[i], arr[r]);

    reverse(i+1, r-1);
}

int main()
{
    cout<<"Before reverse: "<<endl;

    for(auto i: arr)
    {
        cout<<i<<" ";
    }

    cout<<endl;

    reverse(0, n-1);

    cout<<"After reverse: "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}