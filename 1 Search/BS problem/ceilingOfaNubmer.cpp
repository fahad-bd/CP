#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;


    while(start<=end){
        int mid = start +(end - start)/2;

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
    return start;
}

int main()
{
    int arr[] = {2,3,5,9,14,16,18};
    int index = binarySearch(arr,7,15);
    cout<<index<<endl;

    return 0;
}