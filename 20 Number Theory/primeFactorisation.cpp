#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> factor;
    for(int i=2; i*i <= n; i++){
        while(n % i == 0){
            factor.push_back(i);
            n /= i;
        }
    }
    if(n > 1) factor.push_back(n);

    for(auto i: factor) cout<<i<<" ";
}