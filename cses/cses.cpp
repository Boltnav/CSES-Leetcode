#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1000000007
const ll MOD = 1e9 + 7;

int main()
{
    ll n, q; cin >> n >> q;
    ll arr[n]; for (ll i = 0; i < n; i++){cin >> arr[i];}
    ll pref[n]; pref[0] = arr[0]; for (ll i = 1; i < n; i++){pref[i] = pref[i-1] + arr[i];}
    for (ll i = 0; i < q; i++)
    {
        ll a, b; cin >> a >> b;
        if (a == 1 && b == 1){cout << arr[0] << endl;}
        else if (a == 1){cout << pref[b-1] << endl;}
        else{
        cout << pref[b-1] - pref[a-2] << endl;}
    }
}
