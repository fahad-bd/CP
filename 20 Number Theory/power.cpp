#include<bits/stdc++.h>
using namespace std;
const long long int M = 1e18+7;

long long binMultiply(long long a, long long b){
    long long ans = 0;
    while(b>0){
        if(b&1){
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b = b >> 1;
    }
    return ans;
}

long long power(long long a, long long b){
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = binMultiply(ans, a);
        }
        a = binMultiply(a,a);
        b = b >> 1;
    }
    return ans;
}

int main()
{
    cout<<power(4,2)<<endl;
}