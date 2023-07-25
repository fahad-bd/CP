#include<iostream>
using namespace std;

char binarySearch(char letters[], int size, char key){
    int start = 0;
    int end = size - 1;
    

    while(start <= end){
        int mid = start +(end - start)/2;

        if(key > letters[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return letters[start % size];
}

int main()
{
    char arr[] = {'c','f','j'};
    char index = binarySearch(arr,3,'a');
    cout<<index<<endl;

    return 0;
}