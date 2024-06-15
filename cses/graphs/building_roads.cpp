// dfs, connected components
// [adjacency LIST]

#include <bits/stdc++.h>
using namespace std;

// brev

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

int main()
{
    int n, m; cin >> n >> m;
    vector <vector <int>> graph(n+1);
    vector <int> visited (n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int count = 0;
    vector <int> one_vertex_of_each_component_not_connected_to_initial_component;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(visited, graph, i);
            one_vertex_of_each_component_not_connected_to_initial_component.push_back(i);
            count++;
        }
    }

    // NOTE: the first element in one_vertex_of_each_component_not_connected_to_initial_component 
    //       is the 1st element of the graph itself. need to skip that.
    cout << count - 1 << endl;
    for (int i = 1; i < count; i++)
    {
        cout << one_vertex_of_each_component_not_connected_to_initial_component[0] << " " << one_vertex_of_each_component_not_connected_to_initial_component[i] << endl;
    }
}