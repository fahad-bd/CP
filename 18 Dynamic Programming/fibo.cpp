#include<iostream>
using namespace std;
//O(n)
int ara[35];

int fib(int n)
{
    if(n <= 2) return 1;
    if(ara[n] != 0) 
    {
        return ara[n];
    }
    ara[n] = fib(n-1) + fib(n-2);

    return ara[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}