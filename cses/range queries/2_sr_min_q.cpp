#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q; cin >> n >> q;
    vector <int> x (n); for (int i = 0; i < n; i++){cin >> x[i];}
    vector <int> minimum (n); int cur = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < cur){cur = x[i];}
        minimum[i] = cur;
    }
    for (int i = 0; i < q; i++)
    {
        int a, b; cin >> a >> b;
        cout << minimum[a-1] << " " << minimum[b-1] << endl;
        // cout << min(minimum[a-1], minimum[b-1]) << endl;
    }
}