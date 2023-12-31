// time complexity O(n)
// space complexity O(n)

#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i+1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout<<"How many data do you want to input: ";
    cin>>size;
    int arr[size];
    cout<<"Input the data: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"What element do you want to search: ";
    int key;
    cin>>key;

    cout<<"Your element is found in position: ";
    cout<<linearSearch(arr,size,key)<<endl;
    return 0;
}