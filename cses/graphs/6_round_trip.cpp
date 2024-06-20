// dfs, checking if any neighbour has already been visited to find a cycle.

#include <bits/stdc++.h>
using namespace std;

bool dfs (vector <int>& par, vector <int>& vis, vector<vector<int>>& graph, int v)
{
    vis[v] = 1;
    int end = v;
    for (int u : graph[v])
    {
        if (u == par[v]) continue;      // the parent should be skipped [already visited, but can't form cycle]
        if (vis[u])
        {
            vector <int> path;
            while (v != u && v != -1)
            {
                path.push_back(v);
                v = par[v];
            }
            path.push_back(u); 
            if (path.size() >= 3)
            {
                path.push_back(end);
                cout << path.size() << endl;
                for (int i = 0; i < path.size(); i++){cout << path[i] << " ";}
                return true;
            }
        }
        else
        {
            par[u] = v;
            if (dfs(par, vis, graph, u))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m; cin >> n >> m;
    vector <vector <int>> graph(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector <int> par (n+1, -1);
    vector <int> vis (n+1, 0);
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(par, vis, graph, i))
            {
                flag = true;
                break;
            }
        }
    }
    if (!flag){cout << "IMPOSSIBLE";}
}