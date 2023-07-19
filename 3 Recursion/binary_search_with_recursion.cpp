#include<iostream>
#include <string>

using namespace std;

int BS(int arr[], int key, int start, int end){
    if(start > end){
        return -1;
    }
    
    int mid = start + (end - start) / 2;
    if(arr[mid] == key){
        return mid;
    }
    if(key < arr[mid]){
        return BS(arr, key, start, mid - 1);
    }
    return BS(arr, key, mid + 1, end);
}

int main()
{
    int arr[] ={1,2,3,4,5,6,7,8,9,0,11,12,13,14,15};
    int key = 11;
    
    cout<<BS(arr, key, 0, 15);
    cout<<endl;
    return 0;
}
