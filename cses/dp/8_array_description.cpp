#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long MOD = 1e9 + 7;

int main()
{
    ll n, m; cin >> n >> m;
    ll x[n]; for (ll i = 0; i < n; i++){cin >> x[i];}
    ll dp[n+1][m+1];
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
           dp[i][j] = 0;
        }
    }
    // initialisation
    if (x[0] == 0)
    {
        for (ll j = 1; j <= m; j++){dp[1][j] = 1;}
    }
    else
    {
        dp[1][x[0]] = 1;
    }
    for (ll i = 2; i <= n; i++)
    {
        ll current = x[i-1];
        if (current == 0)
        {   
            for (ll j = 1; j <= m; j++)
            {
                
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
        else
        {
            dp[i][current] = dp[i-1][current-1] + dp[i-1][current] + dp[i-1][current+1];
            dp[i][current] %= MOD;
        }
    }

    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    ll sum = 0;
    for (ll i = 0; i <= m; i++){(sum += dp[n][i]) %= MOD;}
    // cout << sum << endl;
}