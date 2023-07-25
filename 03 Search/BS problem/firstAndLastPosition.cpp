/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
if not found output: [-1,-1]
*/

#include"/Users/local/include/bits/stdc++.h"
using namespace std;

int SearchIndex(int arr[], int key, int size, bool findStartIndex);

void searchRange(int arr[], int size, int key, int answer[]){

    //answer[] = {-1,-1};

    //check for first occurrence if target first
    answer[0] = SearchIndex(arr, key, size, true);
    if(answer[0] != -1)
    answer[1] = SearchIndex(arr, key, size, false);


}

//this function just returns the index value of key
int SearchIndex(int arr[], int key, int size, bool findStartIndex){
    
    int ans = -1;
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
            //potential answer found
            ans = mid;
            if(findStartIndex == true){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
    }
    return ans;
}

int main()
{
    int arr[]={1,2,3,4,5,7,7,7,7,7,8};
    int answer[]={-1,-1};

    searchRange(arr,11,7,answer);

    cout<<answer[0]<<" "<<answer[1]<<endl;
    
    return 0;
}