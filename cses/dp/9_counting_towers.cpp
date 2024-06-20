// pretty solid explanation in the attached image

#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;

int main()
{
    int t; cin >> t; int length = t;
    vector <int> vec; long long max = -1;
    while (t--)
    {
        int n; cin >> n; vec.push_back(n);
        if (n > max){max = n;}
    }
    vector <long long> a (max+1); vector <long long> b (max+1);
    // a = seperate, b = together
    a[1] = 1; b[1] = 1;
    for (int i = 2; i <= max; i++)
    {
        (a[i] = (4 * a[i-1]) + b[i-1]) %= MOD;
        (b[i] = a[i-1] + (2 * b[i-1])) %= MOD;
    }
    for (int i = 0; i < length; i++)
    {
        cout << (a[vec[i]] + b[vec[i]]) % MOD << endl;
    }
}