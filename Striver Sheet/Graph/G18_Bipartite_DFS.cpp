// Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int V, vector<int> adj[], int i, vector<int> &color, int colour)
    {
        color[i] = colour;

        for (auto it : adj[i])
        {
            if (color[it] == -1)
            {
                if (!dfs(V, adj, it, color, !colour))
                    return false;
            }
            else if (color[it] == colour)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(V, adj, i, color, 0) == false)
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends