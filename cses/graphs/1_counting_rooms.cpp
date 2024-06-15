#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> & map, int row, int col, int rows, int cols)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols || map[row][col] != '.'){return;}
    map[row][col] = '#';
    dfs(map, row-1, col, rows, cols);
    dfs(map, row+1, col, rows, cols);
    dfs(map, row, col-1, rows, cols);
    dfs(map, row, col+1, rows, cols);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map;
    for (int i = 0; i < n; i++)
    {
        vector <char> tmp;
        for (int j = 0; j < m; j++)
        {
            char x; cin >> x; tmp.push_back(x);
        }
        map.push_back(tmp);
    }
    int count = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (map[row][col] == '.')
            {
                dfs(map, row, col, n, m);
                count++;
            }
        }
    }
    cout << count;
}