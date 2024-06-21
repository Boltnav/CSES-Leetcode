#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// ll INF = 1e9 + 7;
ll INF = numeric_limits<long long>::max();

void dijkstra(vector<vector<pair<ll, ll>>>& graph, vector<ll>& dist,
              vector<ll>& parent, ll s)
{
    ll n = graph.size() - 1; 
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        // Node with the smallest distance
        ll v = pq.top().second; 
        // Distance to this node
        ll d_v = pq.top().first; 
        pq.pop();

        // If the current distance is not equal to the distance in the dist array, skip it
        // Explanation:
        // In Dijkstra's algorithm with a priority queue (min-heap), we repeatedly extract
        // the node with the smallest distance value. However, because of the way priority 
        // queues work, a node can be pushed into the queue multiple times with different 
        // distance values. This can happen if a shorter path to a node is found after it 
        // has already been pushed into the queue with a longer distance.
        if (d_v != dist[v])
            continue;

        // Relaxation step
        for (auto edge : graph[v])
        {
            ll to = edge.first; // Neighbor node
            ll len = edge.second; // Edge weight

            // If a shorter path to `to` is found
            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
                parent[to] = v;
                // Push the updated distance to the priority queue
                pq.push({dist[to], to}); 
            }
        }
    }
}

// Restores path from s to t
vector<ll> restore_path(ll s, ll t, vector<ll> const& parent)
{
    vector<ll> path;
    if (parent[t] == -1) // If t is unreachable
        return path;

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
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n + 1); // Adjust size for 1-based indexing
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        // add/remove if undirected/directed
        // graph[b].push_back({a, c});  
    }

    vector<ll> parent(n + 1, -1); // Adjust size for 1-based indexing
    // Let's start at vertex s (source)
    ll s = 1;
    vector<ll> dist(n + 1, INF); // Adjust size for 1-based indexing

    dijkstra(graph, dist, parent, s);

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    
    // vector<ll> path = restore_path(s, n, parent);
    // if (path.empty())
    // {
    //     cout << -1 << endl;
    // }
    // else
    // {
    //     for (ll i = 0; i < path.size(); i++)
    //     {
    //         cout << path[i] << " ";
    //     }
    //     cout << endl;
    // }
}
