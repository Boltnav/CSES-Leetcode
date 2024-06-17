// 0-1 knapsack
// https://en.wikipedia.org/wiki/Knapsack_problem

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x; cin >> n >> x;
    vector <int> price (n); vector <int> page (n);
    for (int i = 0; i < n; i++){cin >> price[i];} for (int i = 0; i < n; i++){cin >> page[i];}
    vector <int> dp (x+1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }
        // for (int j = 0; j <= x; j++){cout << dp[j] << " ";}
        // cout << endl;
    }   
    cout << dp[x];
}