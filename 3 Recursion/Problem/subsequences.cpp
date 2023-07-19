//contigous or non cotigous sequesces but follows the order
#include<bits/stdc++.h>
using namespace std;

void _print(int index, vector<int> &a, int arr[], int n)
{
    if(index==n)
    {
        for(auto i: a)
        {
            cout<<i<<" ";
        }
        if(a.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    _print(index+1,a,arr,n); //if comment it and uncomment next function print will high to low
    a.push_back(arr[index]);
    _print(index+1,a,arr,n);
    a.pop_back();
    //_print(index+1,a,arr,n); 
}

int main()
{
    int arr[]={3,2,1};
    int n=3;
    vector<int>a;
    _print(0,a,arr,n);
    return 0;
}