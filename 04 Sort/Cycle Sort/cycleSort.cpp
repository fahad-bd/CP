#include<iostream>
using namespace std;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void cycleSort(int arr[], int n){
    int i=0;
    while(i<n){
        int corrent = arr[i]-1;
        if(arr[i] != arr[corrent]){
            swap(arr,i,corrent);
        }
        else{
            i++;
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
    
    cycleSort(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}