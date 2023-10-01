#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class edge
    {
    public:
        int source;
        int destination;
        int weight;
    };
    bool compareInterval(edge e1, edge e2)
    {
        return (e1.weight < e2.weight);
    }
    class subset
    {
    public:
        int parent;
        int rank;
    };
    int findParent(int value, subset *parent)
    {
        if (value == parent[value].parent)
        {
            return value;
        }
        parent[value].parent = findParent(parent[value].parent, parent);
        return parent[value].parent;
    }

    void mst(edge *edgeArr, int n, int e, edge *output)
    {
        sort(edgeArr, edgeArr + e, compareInterval);
        subset *parent = new subset[n];
        for (int i = 0; i < n; i++)
        {
            parent[i].parent = i;
            parent[i].rank = 0;
        }
        int count = 0;
        int index = 0;
        while (count < (n - 1))
        {
            edge currEdge = edgeArr[index];
            int sourceParent = findParent(currEdge.source, parent);

            int destParent = findParent(currEdge.destination, parent);

            if (sourceParent != destParent)
            {
                output[count] = currEdge;
                count++;
                if (parent[sourceParent].rank > parent[destParent].rank)
                {
                    parent[destParent].parent = sourceParent;
                }
                else if (parent[sourceParent].rank < parent[destParent].rank)
                {
                    parent[sourceParent].parent = destParent;
                }
                else
                {
                    parent[destParent].parent = sourceParent;
                    parent[sourceParent].rank++;
                }
            }
            index++;
        }
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int e = (n * (n - 1)) / 2;
        edge *edgeArr = new edge[e];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                edge e1;
                e1.source = i;
                e1.destination = j;
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                e1.weight = (abs(x1 - x2) + abs(y1 - y2));
                edgeArr[i] = e1;
            }
        }

        edge *output = new edge[n - 1];
        mst(edgeArr, n, e, output);
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans += output[i].weight;
        }

        return ans;
    }
};