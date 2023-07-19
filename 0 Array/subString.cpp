/*
input:
2
5 5
abcec
1 2
2 5
3 5
1 5
1 4
5 5
aabbc
1 2
2 5
3 5
1 5
1 4
output
NO
NO
YES
NO
No
YES
N0
YES
YES
YES
Created by Fahad Ahammed
*/
#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        while(q--){
            int l,r;
            cin>>l>>r;
            int hsh[26];
            for(int i=0;i<26;i++){
                hsh[i]=0;
            }
            l--;
            r--;
            for(int i = l; i<=r; i++){
                hsh[s[i]-'a']++;
            }
            int oddCt = 0;
            for(int i=0;i<26;i++){
                if(hsh[i]%2 != 0) oddCt ++;
            }
            if(oddCt > 1) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    return 0;
}