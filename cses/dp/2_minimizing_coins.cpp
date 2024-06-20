#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1000000007
const ll MOD = 1e9 + 7;
 
int main()
{
    int n, x; cin >> n >> x;
    vector <int> coins(n); for (int i = 0; i < n; i++){cin >> coins[i];}
    vector <int> dp(x+1, INF);
    dp[0] = 0; 
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            if (i - coins[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    // for (int i = 0; i <= x; i++){cout << dp[i] << " ";}
    // cout << dp[n];
    if (dp[x] == INF){cout << -1;}
    else {cout << dp[x];}
}