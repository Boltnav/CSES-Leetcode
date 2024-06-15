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