// Problem Link: https://leetcode.com/problems/number-of-enclaves/
// Similar to G14_SurroundedRegions.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    if (grid[i][j] == 1 && visited[i][j] == 0)
                    {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int row[] = {-1, 0, 1, 0};
            int col[] = {0, -1, 0, 1};
            for (int k = 0; k < 4; k++)
            {
                int r = i + row[k];
                int c = j + col[k];
                if (r >= 0 && r < n && c >= 0 && c < m && visited[r][c] == 0 && grid[r][c] == 1)
                {
                    q.push({r, c});
                    visited[r][c] = 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};