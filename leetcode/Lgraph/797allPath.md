### Method 1

```cpp
class Solution {
public:
    void recurPath(vector<vector<int>>& graph, vector<bool>& vis, int src, int dest, vector<vector<int>> &ans, vector<int> &path) {
        // Add current node to the path
        path.push_back(src);

        // If source is destination, add the current path to the result
        if (src == dest) {
            ans.push_back(path);
        } else {
            // Visit all the neighbors
            vis[src] = true;
            for (int neighbour : graph[src]) {
                if (!vis[neighbour]) {
                    recurPath(graph, vis, neighbour, dest, ans, path);
                }
            }
            vis[src] = false; // Backtrack
        }

        // Remove current node from path (backtracking)
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int src = 0;
        int dest = n - 1;
        vector<bool> vis(n, false);
        vector<vector<int>> ans;
        vector<int> path;

        recurPath(graph, vis, src, dest, ans, path);
        return ans;
    }
};

```

### Method 2

```cpp

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        if (graph.empty()) return ans;

        vector<int> path;
        dfs(graph, ans, path, 0, graph.size() - 1);
        return ans;
    }

private:
    void dfs(const vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int start, int destination) {
        path.push_back(start);
        if (start == destination) {
            ans.push_back(path);
        } else {
            for (int neighbor : graph[start]) {
                dfs(graph, ans, path, neighbor, destination);
            }
        }
        path.pop_back(); // backtrack
    }
};

```
