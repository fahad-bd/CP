// one repeated number in array
//  find the repeated number

#include <iostream>
using namespace std;

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int findDuplicate(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {

        if (arr[i] != i + 1)
        {
            int current = arr[i] - 1;
            if (arr[i] != arr[current])
            {
                swap(arr, i, current);
            }
            else{
                return arr[i];
            }
        }
        else{
                i++;
        } 
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<"Output: ";
    cout<<findDuplicate(arr,n)<<endl;
    return 0;
}