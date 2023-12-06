// Problem Link: https://leetcode.com/problems/find-eventual-safe-states/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool dfs(int V, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited, int i, vector<int> &check)
    {
        visited[i] = 1;
        pathVisited[i] = 1;

        for (auto it : adj[i])
        {
            if (pathVisited[it] == 1)
            {
                return true;
            }
            if (visited[it] == 0)
            {
                if (dfs(V, adj, visited, pathVisited, it, check) == true)
                    return true;
            }
        }
        check[i] = 1;
        pathVisited[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> ans;
        vector<int> vis(V, 0);
        vector<int> check(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs(V, adj, vis, pathVis, i, check);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends