#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findSet(int x, vector<int> &parent)
{
    if (parent[x] == x)
    {
        return x;
    }
    int temp = findSet(parent[x], parent);
    parent[x] = temp;
    return temp;
}

bool unionSets(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int lx = findSet(x, parent);
    int ly = findSet(y, parent);

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

int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
         { return b[0] < a[0]; });

    vector<int> parenta(n + 1);
    vector<int> parentb(n + 1);
    vector<int> ranka(n + 1);
    vector<int> rankb(n + 1);
    int counta = 1;
    int countb = 1;

    for (int i = 0; i <= n; i++)
    {
        parenta[i] = i;
        parentb[i] = i;
    }

    int removedEdges = 0;

    for (const vector<int> &e : edges)
    {
        if (e[0] == 3)
        {
            bool mergeda = unionSets(e[1], e[2], parenta, ranka);
            bool mergedb = unionSets(e[1], e[2], parentb, rankb);
            if (mergeda)
            {
                counta++;
            }
            if (mergedb)
            {
                countb++;
            }

            if (!mergeda && !mergedb)
            {
                removedEdges++;
            }
        }
        else if (e[0] == 1)
        {
            bool mergeda = unionSets(e[1], e[2], parenta, ranka);
            if (mergeda)
            {
                counta++;
            }

            if (!mergeda)
            {
                removedEdges++;
            }
        }
        else
        {
            bool mergedb = unionSets(e[1], e[2], parentb, rankb);
            if (mergedb)
            {
                countb++;
            }
            if (!mergedb)
            {
                removedEdges++;
            }
        }
    }

    if (countb != n || counta != n)
    {
        return -1;
    }

    return removedEdges;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << maxNumEdgesToRemove(n, edges) << endl;

    return 0;
}
