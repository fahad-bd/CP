// Problem : https://www.spoj.com/problems/FARIDA/en/
#include <iostream>
using namespace std;

const int N = 1e5;

long long c[N];

int n;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i];
        }

        long long s1 = 0, s2 = 0;

        for(int i=1;i<=n;i++)
        {
            if(i%2)
            s1+=c[i];
            else s2+=c[i];
        }

        cout<<max(s1,s2)<<endl;
    }
    return 0;
}