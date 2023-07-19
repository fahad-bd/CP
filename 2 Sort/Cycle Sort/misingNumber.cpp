//number range is o to n, find the missing number

#include<iostream>
using namespace std;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int missingNumber(int arr[], int n){
    int i=0;
    while(i<n){
        int current= arr[i];
        if(arr[i] < n && arr[i] != arr[current]){
            swap(arr,i,current);
        }
        else i++;
    }

    for (int i = 0; i < n; i++){
        if(arr[i] != i){
            return i;
        }
    }

    return n;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<missingNumber(arr,n)<<endl;
    
    return 0;
}