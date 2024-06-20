#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;
 
int main()
{
    int n; cin >> n; char grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {cin >> grid[i][j];}
    }
    int dp[n][n];
    for (int i = 0; i < n; i++){for (int j = 0; j < n; j++){dp[i][j] = 0;}}
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                if (i > 0)
                {
                    (dp[i][j] += dp[i-1][j]) %= MOD;
                }
                if (j > 0)
                {
                    (dp[i][j] += dp[i][j-1]) %= MOD;
                }
            }
            else {dp[i][j] = 0;}
            // cout << dp[i][j] << " ";
        } 
        // cout << endl;
    }
    
    cout << dp[n-1][n-1];
}