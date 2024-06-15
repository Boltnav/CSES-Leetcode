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