//find peak in mountain array

#include"/Users/local/include/bits/stdc++.h"
using namespace std;

int peakIndexInMountainArray(int arr[],int size){
    int start = 0;
    int end = size -1;

    while(start < end){
        int mid = start + (end - start)/2;

        if(arr[mid] > arr[mid+1]){
            //decreasing part of array and check in left
            end = mid;
        }
        else{
            start = mid + 1;
            //arr[mid + 1] element > arr[mid] element
        }
    }
    return start; //start and end are equal
}


int main()
{
    int arr[]={1,2,3,5,6,5,3,2};
    cout<<"Peek index is: "<<peakIndexInMountainArray(arr,8)<<endl;
    cout<<"Peek element is: "<<arr[peakIndexInMountainArray(arr,8)]<<endl;
    return 0;
}