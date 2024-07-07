#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void grid_dfs(vector<vector<char>> & map, int row, int col, int rows, int cols)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols || map[row][col] != '.'){return;}
    map[row][col] = '#';
    grid_dfs(map, row-1, col, rows, cols);
    grid_dfs(map, row+1, col, rows, cols);
    grid_dfs(map, row, col-1, rows, cols);
    grid_dfs(map, row, col+1, rows, cols);
}

// [adjacency list]
// this solely just marks each visited vertex as 1 in the corresponding visited vector
void dfs(vector <int>& visited, vector <vector<int>>& graph, int i)
{
    stack <int> s;
    s.push(i);
    while (!s.empty())
    {
        // current node of graph
        int v = s.top(); s.pop();
        if (visited[v] == 0)
        {
            visited[v] = 1;
            for (int connected_vertex : graph[v])
            {
                s.push(connected_vertex);
            }
        }
    }
}

// [adjacency list]
// one fanta lite please brev
void bfs(vector <int>& parent, vector <int>& dist, vector <vector<int>>& graph, int start)
{
    queue <int> q;
    q.push(start);
    dist[start] = 1;
    while (!q.empty())
    {
        // extract current node of graph
        int v = q.front(); q.pop();
        for (int connected_vertex : graph[v])
        {
            if (dist[v] + 1 < dist[connected_vertex])
            {
                dist[connected_vertex] = dist[v] + 1;
                q.push(connected_vertex);
                parent[connected_vertex] = v;
            }
        }
    }
}

void dijkstra(vector<vector<pair<ll, ll>>>& graph, vector<ll>& dist,
              vector<ll>& parent, ll s)
{
    ll n = graph.size() - 1; 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
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

// THIS ONLY WORKS FOR DIRECTED GRAPH :)
// returns true for cycle
bool dfs_cycle(int v, vector<vector<int>>& graph, vector<int>& vis) {
    if (vis[v] == 1) return true; // this is the important line
    if (vis[v] == 2) return false; 
    vis[v] = 1; 
    for (int u : graph[v]) 
    {
        if (dfs_cycle(u, graph, vis)) 
        {
            // NOTE: [pretty important]
            // this is basically if you cycle all the way back to the initial vertex v
            return true; 
        }
    }
    vis[v] = 2; // mark as visited
    return false; 
}

bool dfs(vector<vector<int>>& graph, vector<int>& vis, int v, int parent) 
{
    if (vis[v] == 1) return true; // Cycle detected

    vis[v] = 1;
    for (int u : graph[v]) {
        if (u != parent && dfs(graph, vis, u, v)) {
            return true; // Cycle found
        }
    }
    return false;
}

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
    pair <int, int> x;
    pair <int, int>*y = &x;
    y->first = 1;
}