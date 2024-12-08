#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int n, unordered_map<int, unordered_set<int>> &adjUD, unordered_map<int, unordered_set<int>> &adjD, vector<bool> &vis)
{
    int counter = 0;
    vis[node] = true;
    for (auto it : adjUD[node])
    {
        if (!vis[it])
        {
            if (adjD[node].empty() or adjD[node].find(it) == adjD[node].end())
            {
                counter++;
            }
        // cout << "node it counter PRE :  " << node << " " << it << " " << counter << " " << endl;
        counter += dfs(it, n, adjUD, adjD, vis);
        // cout << "node it counter PAST : " << node << " " << it << " " << counter << " " << endl;
        }
    }

    return counter;
}

void bfs(int n, queue<pair<int, int>> &q, vector<int> &result, unordered_map<int, unordered_set<int>> &adjUD, unordered_map<int, unordered_set<int>> &adjD)
{
    while (!q.empty())
    {
        int sz = q.size();
        while(sz--)
        {
            int node = q.front().first, parent = q.front().second;
            q.pop();
            if (result[node] == -1)
            {
                result[node] = (adjD[node].find(parent) != adjD[node].end()) ? result[parent] - 1 : result[parent] + 1;
                for (auto neighbour : adjUD[node])
                    q.push({neighbour, node});
            }
        }
      
    }
}

vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
{
    vector<int> result(n, -1);
    unordered_map<int, unordered_set<int>> adjD, adjUD;
    queue<pair<int, int>> q;
    vector<bool> vis(n, false);

    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        // Undirected AdjList
        adjUD[u].insert(v);
        adjUD[v].insert(u);
        // Directed AdjList
        adjD[u].insert(v);
    }

    result[0] = dfs(0, n, adjUD, adjD, vis);

    // cout << result[0] << endl;

    for (auto nodes : adjUD[0])
    {
        // cout << nodes;
        q.push({nodes, 0});
    }

    bfs(n, q, result, adjUD, adjD);

    return result;
}
int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    vector<int> ans = minEdgeReversals(n, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] <<" ";
    }
    return 0;
}