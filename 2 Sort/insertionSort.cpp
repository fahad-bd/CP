#include<bits/stdc++.h>
using namespace std;
//Memory Complexity O(n)
//Time Complexity O(n^2)

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void insertionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j>0; j--){
            if(arr[j] < arr[j-1]){
                swap(arr,j,j-1);
            }
            else{
                break;
            }
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    insertionSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}