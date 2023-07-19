/*

Created by Fahad Ahammed
*/
#include<bits/stdc++.h>
using namespace std;

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char *str, int s, int e){
    if(s==e) cout<<str<<endl;

    else{
        for (int i = s; i <= e; i++)
        {
            swap(str+s,str+i);
            permutation(str, s+1, e);
            swap(str+s, str+i);
        }
        
    }
}

int main() 
{
    char str[] = "ABC";
    int n = strlen(str);
    permutation(str, 0, n-1);
    return 0;
}