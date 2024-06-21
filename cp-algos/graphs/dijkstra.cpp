#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// ll INF = 1e9+7;
ll INF = numeric_limits<long long>::max();

void dijkstra(vector <vector <pair <ll, ll>>>& graph, vector <ll>& dist,
              vector <ll>& parent, vector <ll>& mark, ll s)
{
    // this is prettyyy darn important as I am using 1-indexing.
    ll n = graph.size() - 1;  
    // iterate a max. of n times. all reachable vertices will get marked.
    for (ll i = 1; i <= n; i++)
    {
        ll v = -1; 
        // just picking the unmarked vertex with minimum d[v]
        for (ll j = 1; j <= n; j++)
        {
            if (!mark[j] && (v == -1 || dist[j] < dist[v]))
            {
                v = j;
            }
        }
        // break if all the vertices reachable from source have been marked
        // and hence the unmarked vertices are unreachable (INF) from source
        if (dist[v] == INF /*|| dist[v] == -1*/)
        {
            break;
        }

        mark[v] = true;

        for (auto edge : graph[v])
        {
            ll w = edge.first;
            ll len = edge.second;
            if (dist[v] + len < dist[w])
            {
                dist[w] = dist[v] + len;
                parent[w] = v;
            }
        }
    }
}

// restores path from s to t
vector <ll> restore_path(ll s, ll t, vector <ll>const& parent)
{
    vector <ll> path;
    for (ll v = t; v != s; v = parent[v])
    {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ll n, m; cin >> n >> m;
    vector <vector <pair <ll, ll>>> graph (n+1);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        // add/remove if undirected/directed
        // graph[b].push_back({a, c});     /
    }

    vector <ll> parent(n+1);
    // let's start at vertex s (source)
    ll s = 1;      //
    vector <ll> dist(n+1, INF);
    vector <ll> mark(n+1, 0);
    dist[s] = 0;

    dijkstra(graph, dist, parent, mark, s);
    
    vector <ll> path = restore_path(s, n, parent);
    if (path.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (ll i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
}