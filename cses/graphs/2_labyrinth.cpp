#include <bits/stdc++.h>
using namespace std;

// 0-up 1-right 2-down 3-left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string step = "URDL";

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> start, end;
    char grid[n][m];
    bool visited[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            visited[i][j] = false;
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }
    visited[start.first][start.second] = true;
    int prevstep[n][m];
    queue <pair <int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        pair <int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair <int, int> v = make_pair(u.first + dx[i])
        }
    }
}