#include<bits/stdc++.h>
using namespace std;

bool palindrome(int i, int n, string s)
{
    if(i>=n/2) return true;

    if(s[i]!=s[n-i-1]) return false;

    return palindrome(i+1, n, s);
}

int main()
{
    string s = "abba";
    int n = s.size();

    cout<<palindrome(0,n,s)<<endl;

    return 0;
}