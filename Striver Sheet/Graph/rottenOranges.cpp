#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();                // rows
        int m = grid[0].size();             // columns
        vector<vector<int>> visited = grid; // copying grid to visited
        int time = 0;
        queue<pair<pair<int, int>, int>> q;

        // pushing all rotten oranges to queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        // BFS
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};
        while (!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = t;

            // checking all 4 directions
            for (int k = 0; k < 4; k++)
            {
                int r = i + row[k];
                int c = j + col[k];
                if (r >= 0 && r < n && c >= 0 && c < m && visited[r][c] == 1)
                {
                    visited[r][c] = 2;
                    q.push({{r, c}, t + 1});
                }
            }
        }
        // checking if any fresh orange is left
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 1)
                    time = -1;
            }
        }
        return time;
    }
};