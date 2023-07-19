// Problem : https://www.spoj.com/problems/FARIDA/en/
#include <iostream>
using namespace std;

const int N = 1e5;
int dp[N];
long long c[N];

int n;

int kill(int i, long s1, long s2)
{
    if (n < i)
    {
        return max(s1, s2);
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    if (i % 2)
        s1 += c[i];
    else
        s2 += c[i];

    long long ans = kill(i + 1, s1, s2);
    dp[i] = ans;

    return ans;
}

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
        for (int i = 1; i <= n; i++)
            dp[i] = -1;

        cout << kill(1, 0, 0) << endl;
    }
    return 0;
}