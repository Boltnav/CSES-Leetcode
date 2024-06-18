#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long MOD = 1e9+7;

int main()
{
    ll n; cin >> n;
    vector <ll> dp (n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = max(i-6, 0); j < i; j++)
        {
            (dp[i] += dp[j]) %= MOD;
        }
    }
    cout << dp[n];
}