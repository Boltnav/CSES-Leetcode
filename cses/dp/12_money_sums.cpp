#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n; int sum = 0;
    vector <int> value (n); for (int i = 0; i < n; i++){cin >> value[i]; sum += value[i];}
    vector <int> dp (sum+1, 0);
    dp[0] = 1;  // method 2
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            if (j - value[i] >= 0)
            {
                if (dp[j - value[i]] == 1)
                {
                    dp[j] = 1;
                }
            }
        }
        // dp[value[i]] = 1;    // method 1
        // for (int j = 0; j <= sum; j++)
        // {
        //     cout << dp[j] << " ";
        // }
        // cout << endl;
    }
    int count = 0; vector <int> out;
    for (int j = 1; j <= sum; j++)
    {
        if (dp[j] == 1){count++; out.push_back(j);}
    }
    cout << count << endl;
    for (int i = 0; i < count; i++){cout << out[i] << " ";}
}