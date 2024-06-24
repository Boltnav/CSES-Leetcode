#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;

// we are going bottom up. 
// we are using dp_i_(j-coins[i]). this is because the same coin can be repeated. it feels like an unbounded dp. not the same though. 

int main()
{
    ll n, x; cin >> n >> x;
    vector <ll> coins (n+1); for (ll i = 1; i <= n; i++) {cin >> coins[i];}
    vector <vector <ll>> dp (n+1, vector <ll> (x+1, 0));
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j - coins[i] >= 0)
            {
                (dp[i][j] += dp[i][j - coins[i]]) %= MOD;
            }
        }
    }
    // for (ll i = 0; i <= n; i++)
    // {
    //     for (ll j = 0; j <= x; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][x];
}