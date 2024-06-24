#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b; cin >> a >> b;
    vector <vector <int>> dp(a+1, vector <int> (b+1, 0));
    dp[1][1] = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i != 1 || j != 1)
            {
                int x, y;
                if (i < j)
                {
                    x = i; y = j - i;
                    dp[i][j] = 1 + dp[x][y];
                }
                else if (i > j) 
                {
                    x = i - j; y = j;
                    dp[i][j] = 1 + dp[x][y];
                } 
                else 
                {
                    dp[i][j] = 0;
                }
                // if (i == j){dp[i][j] = 0;}
                // else
                // {
                //     dp[i][j] = 1e9+7;
                //     for (int x = 0; x < i; x++)
                //     {
                //         dp[i][j] = min(dp[i][j], dp[i-x][j] + dp[x][j] + 1);
                //     }
                //     for (int x = 0; x < j; x++)
                //     {
                //         dp[i][j] = min(dp[i][j], dp[i][j-x] + dp[i][x] + 1);
                //     }
                // }
            }
        }
    }
    // for (int i = 1; i <= a; i++)
    // {
    //     for (int j = 1; j <= b; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[a][b];
}