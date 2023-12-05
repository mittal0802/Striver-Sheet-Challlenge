#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                queue<pair<int, int>> q;
                q.push({i, -1});
                while (!q.empty())
                {
                    int child = q.front().first;
                    int parent = q.front().second;

                    q.pop();
                    for (auto it : adj[child])
                    {
                        if (visited[it] == 0)
                        {
                            visited[it] = 1;
                            q.push({it, child});
                        }
                        else if (parent != it)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};