#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x, vector<int> &parent)
{
    /* if (parent[x] == x)
    {
        return x;
    }
    int temp = find(parent[x], parent);
    parent[x] = temp;
    return temp; */

    if (parent[x] != x)
    {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

bool unionSets(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int lx = find(x, parent);
    int ly = find(y, parent);

    if (lx == ly)
    {
        return false;
    }

    if (rank[lx] > rank[ly])
    {
        parent[ly] = lx;
    }
    else if (rank[lx] < rank[ly])
    {
        parent[lx] = ly;
    }
    else
    {
        parent[lx] = ly;
        rank[ly]++;
    }

    return true;
}

int minCostToSupplyWater(int n, vector<pair<int, pair<int, int>>> &pipes)
{
    vector<pair<int, pair<int, int>>> edges = pipes;
    sort(edges.begin(), edges.end());

    int ans = 0;
    vector<int> parent(n);
    vector<int> rank(n, 1);

    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }

    for (const auto &edge : edges)
    {
        int u = edge.second.first;
        int v = edge.second.second;
        int wt = edge.first;

        if (unionSets(u, v, parent, rank))
        {
            ans += wt;
        }
    }

       return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<pair<int, pair<int, int>>> edges(e);
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = make_pair(wt, make_pair(u, v));
    }

    cout << minCostToSupplyWater(v, edges) << endl;

    return 0;
}
