/*

Created by Fahad Ahammed
*/
#include<bits/stdc++.h>
using namespace std;

int find(int arr[], int index, int size, int key){
    if(index == size){
        return -1;
    }

    if(arr[index]==key){
        return index;
    } 

    else {
       return find(arr,index+1,size,key);
    }
}

int main() 
{
    int size = 10;
    int arr[] = {0,1,2,3,4,5,6,7,8,9};

    cout<<find(arr,0,10,4)<<endl;
    return 0;
}