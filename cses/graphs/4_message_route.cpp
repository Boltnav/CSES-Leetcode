// bfs, shortest path b/w two vertices
// [adjacency LIST]

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n, m; cin >> n >> m;
    vector <vector <int>> graph(n+1);
    vector <int> dist (n+1, 1e9);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector <int> parent (n+1, -1);
    bfs(parent, dist, graph, 1);
    if (dist[n] == 1e9)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        // for (auto i : dist){cout << i << " ";} cout << endl;
        cout << dist[n] << endl; 
        vector <int> path;
        int v = n;
        while (v != 1)
        {
            path.push_back(v);
            v = parent[v];
        }
        cout << 1 << " ";
        for (int i = path.size()-1; i >= 0; i--)
        {
            cout << path[i] << " ";
        } 
        cout << endl;
    }
}