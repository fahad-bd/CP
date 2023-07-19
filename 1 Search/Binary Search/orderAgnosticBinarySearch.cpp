#include <iostream>
using namespace std;

int orderAgnosticBS(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

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

        if (!isAcending)
        {
            if (key < arr[mid])
            {
                start = mid - 1;
            }
            else
            {
                end = mid + 1;
            }
        }
        else
        {
            if (key > arr[mid])
            {
                start = mid - 1;
            }
            else
            {
                end = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};

   // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int index = orderAgnosticBS(arr, 10, 3);
    cout<< index <<endl;

    return 0;
}
