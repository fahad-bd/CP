#include<bits/stdc++.h>
using namespace std;

//O(logN) complexity

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int low=0, high = n-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(a[mid] == k){
            cout<<"Value found at index: "<<mid<<endl;
            return 0;
        }
        else if(a[mid] > k){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout<<"Not found!"<<endl;
    return 0;
}