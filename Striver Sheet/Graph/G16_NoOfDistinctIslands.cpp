// Problem Link: https://leetcode.com/problems/number-of-distinct-islands/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &island)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            island.push_back({r - i, c - j});

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, -1, 0, 1};

            for (int k = 0; k < 4; k++)
            {
                int row = r + delrow[k];
                int col = c + delcol[k];

                if (row >= 0 && row < n && col >= 0 && col < m && visited[row][col] == 0 && grid[row][col] == 1)
                {
                    q.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        set<vector<pair<int, int>>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == 1)
                {
                    vector<pair<int, int>> island;
                    bfs(i, j, visited, grid, island);
                    s.insert(island);
                }
            }
        }
        return s.size();
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends