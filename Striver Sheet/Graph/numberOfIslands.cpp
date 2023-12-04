#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void bfs(vector<vector<char>> &arr, vector<vector<int>> &visited, int i, int j, int n, int m)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            // instead of visiting all 4 neighbours individually, we can run a loop
            int row[] = {-1, 0, 1, 0};
            int col[] = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++)
            {
                int delrow = row[i];
                int delcol = col[i];
                if (x + delrow >= 0 && x + delrow < n && y + delcol >= 0 && y + delcol < m && arr[x + delrow][y + delcol] == '1' && visited[x + delrow][y + delcol] == 0)
                {
                    visited[x + delrow][y + delcol] = 1;
                    q.push({x + delrow, y + delcol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == 0)
                {
                    bfs(grid, visited, i, j, n, m);
                    count += 1;
                }
            }
        }
        return count;
    }
};