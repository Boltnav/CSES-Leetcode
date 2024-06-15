#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;

int main()
{
    int n, m; cin >> n >> m;
    int x[n]; for (int i = 0; i < n; i++){cin >> x[i];}
    int dp[n+1][m+1];
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 0)
        {   
            for (int j = 1; j <= m; j++)
            {
                
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
        else
        {

        }
    }
}