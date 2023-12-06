// Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Using visited array {0, 1, 2} to detect cycle in directed graph using DFS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int V, vector<int> adj[], vector<int> &visited, int i)
    {
        visited[i] = 2;

        for (auto it : adj[i])
        {
            if (visited[it] == 2)
            {
                return true;
            }
            if (visited[it] == 0)
            {
                if (dfs(V, adj, visited, it) == true)
                    return true;
            }
        }
        visited[i] = 1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (dfs(V, adj, visited, i) == true)
                    return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

// Using visited and pathVisited array to detect cycle in directed graph using DFS

// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution
// {
// public:
//     // Function to detect cycle in a directed graph.
//     bool dfs(int V, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited, int i)
//     {
//         visited[i] = 1;
//         pathVisited[i] = 1;

//         for (auto it : adj[i])
//         {
//             if (pathVisited[it] == 1)
//             {
//                 return true;
//             }
//             if (visited[it] == 0)
//             {
//                 if (dfs(V, adj, visited, pathVisited, it) == true)
//                     return true;
//             }
//         }
//         pathVisited[i] = 0;
//         return false;
//     }
//     bool isCyclic(int V, vector<int> adj[])
//     {
//         // code here

//         vector<int> visited(V, 0);
//         vector<int> pathVisited(V, 0);

//         for (int i = 0; i < V; i++)
//         {
//             if (visited[i] == 0)
//             {
//                 if (dfs(V, adj, visited, pathVisited, i) == true)
//                     return true;
//             }
//         }
//         return false;
//     }
// };

// //{ Driver Code Starts.

// int main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int V, E;
//         cin >> V >> E;

//         vector<int> adj[V];

//         for (int i = 0; i < E; i++)
//         {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//         }

//         Solution obj;
//         cout << obj.isCyclic(V, adj) << "\n";
//     }

//     return 0;
// }

// // } Driver Code Ends