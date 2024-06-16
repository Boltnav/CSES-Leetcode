// dfs, checking if any neighbour has already been visited

#include <bits/stdc++.h>
using namespace std;

bool flag = false;

void dfs(vector <int>& parent, vector <int>& visited, vector <vector<int>>& graph, int i)
{
    stack <int> s;
    s.push(i);
    visited[i] = 1;
    while (!s.empty())
    {
        // current node of graph
        int v = s.top(); s.pop();
        if (visited[v] == 0)
        {
            visited[v] = 1;
            for (int connected_vertex : graph[v])
            {
                if (visited[connected_vertex] == 0)
                {
                    parent[connected_vertex] = v;
                    s.push(connected_vertex);
                }
                else if (visited[connected_vertex] == 1)
                {
                    int start = connected_vertex;
                    int end = v;
                    vector <int> path;
                    path.push_back(start);
                    path.push_back(end);
                    while (end != start && end != -1)
                    {
                        end = parent[end];
                        path.push_back(end);
                    }
                    if (path[path.size()-1] != -1 && path.size() > 3)
                    {
                        cout << path.size() << endl;
                        for (int vertex : path)
                        {
                            cout << vertex << " ";
                        }
                        cout << endl;
                        flag = true;
                    }
                }
            }
        }
    }
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
    vector <int> parent (n+1, -1);
    vector <int> visited (n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(parent, visited, graph, i);
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag){cout << "IMPOSSIBLE";}
}