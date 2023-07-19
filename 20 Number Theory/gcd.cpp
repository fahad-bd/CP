#include<bits/stdc++.h>
using namespace std;
int lcm(int a, int b){ //O(1)
    return (a*b)/gcd(a,b);
}

int gcd(int a, int b){ //O(log(N))
    if(b==0) return a;
    return gcd(b, a%b);
}
int main()
{
    cout<<"GCD: "<<endl;
    cout<<gcd(12,4)<<endl;
    cout<<gcd(4,12)<<endl; 
    cout<<"LCM: "<<endl;
    cout<<lcm(12,4)<<endl;
    cout<<lcm(4,12)<<endl;   
    return 0;
}