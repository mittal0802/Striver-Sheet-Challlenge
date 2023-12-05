// Problem Link: https://leetcode.com/problems/surrounded-regions/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> mat, int n, int m)
    {
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int r = i + row[k];
            int c = j + col[k];
            if (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == 'O' && visited[r][c] == 0)
            {
                dfs(r, c, visited, mat, n, m);
            }
        }
    }
    void solve(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            if (visited[0][i] == 0 && mat[0][i] == 'O')
            {
                dfs(0, i, visited, mat, n, m);
            }
            if (visited[n - 1][i] == 0 && mat[n - 1][i] == 'O')
            {
                dfs(n - 1, i, visited, mat, n, m);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i][0] == 0 && mat[i][0] == 'O')
            {
                dfs(i, 0, visited, mat, n, m);
            }
            if (visited[i][m - 1] == 0 && mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1, visited, mat, n, m);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};