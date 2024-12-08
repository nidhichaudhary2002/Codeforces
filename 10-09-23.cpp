#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(unordered_map<int, unordered_set<int>> adjUn,
            unordered_map<int, unordered_set<int>> adjD, int curr,
            vector<bool> vis)
    {
        vis[curr] = true;

        int cnt = 0;
        for (auto it : adjUn[curr])
        {
            if (!vis[it])
            {
                if (!adjD[curr].empty() || adjD[curr].find(it) != adjD[curr].end())
                {
                    cnt++;
                }
                cnt += dfs(adjUn, adjD, it, vis);
            }
        }
        return cnt;
    }

    void bfs(unordered_map<int, unordered_set<int>> adjUn,
             unordered_map<int, unordered_set<int>> adjD, vector<int> &result,
             vector<bool> vis, queue<pair<int, int>> q)
    {
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                if (result[node] == -1)
                {
                    if (adjD[node].find(parent) != adjD[node].end())
                    {
                        result[node] = result[parent] - 1;
                    }
                    else
                    {
                        result[node] = result[parent] + 1;
                    }
                    for (auto it : adjUn[node])
                    {
                        q.push({it, node});
                    }
                }
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, unordered_set<int>> adjUn;
        unordered_map<int, unordered_set<int>> adjD;

        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adjUn[a].insert(b);
            adjUn[b].insert(a);
            adjD[a].insert(b);
        }
        vector<int> result(n, -1);
        vector<bool> vis;
        result[0] = dfs(adjUn, adjD, 0, vis);
        queue<pair<int, int>> q;
        for (auto it : adjUn[0])
        {
            q.push({it, 0});
        }

        bfs(adjUn, adjD, result, vis, q);
        return result;
    }
};

