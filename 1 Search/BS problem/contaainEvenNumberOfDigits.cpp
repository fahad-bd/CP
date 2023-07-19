/*
Given an array nums of integers, return how many of them contain an even number of digits.

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
*/

#include<iostream>
using namespace std;

bool nEven(int num){
    int c=0;
    if(num<0) num*=-1;

    while(num>0){
        c++;
        num/=10;
    }

    return c%2==0;
}

int findNumbers(int arr[], int n){
    int count = 0;
    for(int i =0; i<n; i++){
        if(nEven(arr[i])){
            count++;
        }
    }
    return count;
}

int main()
{
    int num[]={12,345,2,6,7896};
    cout<<findNumbers(num, 5)<<endl;
    return 0;
}