#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &graph)
{
    vector<int> ans(numCourses, 0);
    vector<int> indegree(numCourses, 0);

    for (int i = 0; i < numCourses; i++)
    {
        for (int nbrs : graph[i])
        {
            indegree[nbrs]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int idx = 0;
    while (!q.empty())
    {
        int rem = q.front();
        q.pop();
        ans[idx] = rem;
        idx++;

        for (int nbrs : graph[rem])
        {
            indegree[nbrs]--;
            if (indegree[nbrs] == 0)
            {
                q.push(nbrs);
            }
        }
    }

    if (idx == numCourses)
    {
        return ans;
    }
    else
    {
        return vector<int>{-1};
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        graph[i] = vector<int>();
    }

    for (int i = 0; i < m; i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        graph[v].push_back(u);
    }

    vector<int> ans = findOrder(n, graph);

    for (int val : ans)
    {
        cout << val << " ";
    }

    return 0;
}
