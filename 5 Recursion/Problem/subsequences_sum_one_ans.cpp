#include<bits/stdc++.h>
using namespace std;

bool _print(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if(ind == n)
    {
        if(s == sum)
        {
            for(auto it : ds)
            {
                cout<< it << " ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if(_print(ind+1, ds, s, sum, arr, n)==true){
        return true;
    }

    s -= arr[ind];
    ds.pop_back();

    if(_print(ind+1, ds, s, sum, arr, n)==true){
        return true;
    }

    return false;
}

int main()
{
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;
    _print(0,ds,0,sum,arr,n);
    return 0;
}