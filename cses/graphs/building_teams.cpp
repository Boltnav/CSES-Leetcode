// using bfs to test bipartiteness

#include <bits/stdc++.h>
using namespace std;

// 
int bfs(vector <int>& color, vector <vector<int>>& graph, int start)
{
    queue <int> q;
    q.push(start);
    color[start] = 1;
    while (!q.empty())
    {
        // extract current node of graph
        int v = q.front(); q.pop();
        for (int connected_vertex : graph[v])
        {
            if (color[connected_vertex] == -1)
            {
                color[connected_vertex] = 1 - color[v];
                q.push(connected_vertex);
            }
            else if (color[v] == color[connected_vertex])
            {
                return -1;
            }
        }
    }
    return 1;
}

int main()
{
    int n, m; cin >> n >> m;
    vector <vector <int>> graph(n+1);
    vector <int> color (n+1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    bool isBipartite = true;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (bfs(color, graph, i) == -1)
            {
                isBipartite = false;
                break;
            }
        }
    }
    if (!isBipartite)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i]+1 << " ";
        }
    }
}