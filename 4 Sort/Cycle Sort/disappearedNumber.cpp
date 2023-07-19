//find all numbers disappeared_number in the array
//input: [4,3,2,7,8,2,3,1,0]
//output: [5,6]

#include<iostream>
#include<list>
using namespace std;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

list<int> disappeared_number(int arr[], int n){
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

    list<int> number;

    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            number.push_back(i+1);
        }
    }

    return number;
}



int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    list<int> l =  disappeared_number(arr,n);

    for(auto i: l){
        cout<<i<<" ";
    }

    return 0;
}