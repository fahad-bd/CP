//find in mountain array

#include"/Users/local/include/bits/stdc++.h"
using namespace std;


int orderAgnosticBS(int arr[], int start, int end, int key)
{

    // find whether the array is is sorted ascending or descendig order

    // bool isAscendig = arr[start] < arr[end];

    bool isAcending;
    if (arr[start] < arr[end])
    {
        isAcending = true;
    }
    else
    {
        isAcending = false;
    }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (isAcending)
        {
            if (key < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (key > arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return -1;
}


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

int search(int arr[], int size, int key){
    int peak = peakIndexInMountainArray(arr,size);
    int firstTry = orderAgnosticBS(arr,0,peak,key);//search in left part from peak
    if(firstTry != -1){
        return firstTry; //key is found in left part 
    }
    return orderAgnosticBS(arr,peak+1,size-1,key);//search in righi part from peak
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,4,3,2,2,1}; //s=12
    cout<<search(arr,12,6)<<endl;
    return 0;
}