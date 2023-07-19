//problem : https://atcoder.jp/contests/dp/tasks/dp_b

#include<iostream>
using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9;

int h[N], dp[N];
int n,k;

int stone(int n)
{
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];

    int ans = INF;

    for(int i = 1; i <= k ; i++)
    {
        if(n - i <= 0)
        {
            break;
        }
        int candidate_ans = stone(n - i) + abs(h[n] - h[n-i]);
        ans = min(ans, candidate_ans);
    }
    dp[n] = ans;
    return dp[n];
}

int main()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> h[i];
    }

    for(int i = 1 ; i <= n ; i++)
    {
        dp[i] = -1;
    }

    cout << stone(n) << endl;
    return 0;
}