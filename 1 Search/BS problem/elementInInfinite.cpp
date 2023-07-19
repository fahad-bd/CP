//find postion of an element in a sorted array of infinite numbers

#include"/Users/local/include/bits/stdc++.h"
using namespace std;


int binarySearch(int arr[], int key, int start, int end){
   
    while(start <= end){
        int mid = start + (end - start)/2;

        if(key > arr[mid]){
            start = mid+1;
        }
        else if(key < arr[mid]){
            end = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int ans(int arr[], int key){
    int start = 0;
    int end = 1;

    while(key > arr[end]){
        int newStart = end + 1;
        end = end + (end - start + 1) * 2;
        start = newStart;
    }
    return binarySearch(arr,key,start,end);
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,8,10,11,12,13,14};
    int key = 7;
    cout<<ans(arr,key)<<endl;
    return 0;
}