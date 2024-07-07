#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector <vector <int>>& tree, vector <int>& sub)
{
    int count = 0;
    for (int child : tree[node])
    {
        count += dfs(child, tree, sub);
        count += 1;
    }
    sub[node] = count;
    return count;
}

int main()
{
    int n; cin >> n;
    vector <vector <int>> tree (n+1);
    vector <int> sub (n+1);
    int parent;
    for (int i = 2; i <= n; i++)
    {
        cin >> parent;
        tree[parent].push_back(i);
    }

    dfs(1, tree, sub);

    for (int i = 1; i <= n; i++){cout << sub[i] << " ";} cout << endl;

}
