#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            int w = vec[i][j];
            adj[i].push_back(make_pair(j, w));
            adj[j].push_back(make_pair(i, w));
        }
    }

    // creation of distance array with infinite value initially
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT16_MAX;
    }
    // creation of set on basis (distance,node)
    set<pair<int, int>> st;
    // initialise distance and set with source code
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        //
        st.erase(st.begin());
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int tot, k, a, b;

        cin >> tot >> k >> a >> b;

        pair<int, int> *arr = new pair<int, int>[tot];

        for (int i = 0; i < tot; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }

        vector<vector<int>> adjlist(tot, vector<int>(tot, 0));

        for (int i = 0; i < tot; i++)
        {
            for (int j = 0; j < tot; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (i < k && j < k)
                {
                    continue;
                }
                else
                {
                    adjlist[i][j] = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
                    // adjlist[j][i] = adjlist[i][j];
                }
            }
        }

        int edges = (tot * (tot - 1)) / 2;

        vector<int> dist = dijkstra(adjlist, tot, edges, a);

        cout << "Ans : " << dist[b] / 2 << endl;
    }
    return 0;
}