/*

Created by Fahad Ahammed
*/
#include<bits/stdc++.h>
using namespace std;

bool Sorted(int arr[], int index , int n){
    if(index == n-1) return true;

    return arr[index] < arr[index+1] && Sorted(arr,index+1,n);
}

int main() 
{
    int n = 10;
    int arr[] = {0,1,2,3,4,5,6,7,8,9};

    cout<<Sorted(arr,0,n)<<endl;
    return 0;
}