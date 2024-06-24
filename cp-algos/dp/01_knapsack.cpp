#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n; int x; cin >> x;
    vector <int> weight (n+1); for (int i = 1; i <= n; i++){cin >> weight[i];}
    vector <int> val (n+1); for (int i = 1; i <= n; i++){cin >> val[i];}
    vector <int> dp (x+1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-weight[i]] + val[i]);  
        }
    }
    cout << dp[x];
}

for (int i = 1; i <= n; i++)
{
    for (int j = weight[i]; j <= x; j++)
    {
        dp[j] = max(dp[j], dp[j-weight[i]] + val[i]);
    }
}