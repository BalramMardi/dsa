#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

// Disjoint Set Union (DSU)
struct DSU {
    vi parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y])
                swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
};

// Sieve of Eratosthenes
vi sieve(int n) {
    vi is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    vi primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i])
            primes.pb(i);
    }
    return primes;
}

// Fenwick Tree (Binary Indexed Tree)
struct FenwickTree {
    vi BIT;
    int n;
    FenwickTree(int size) {
        n = size;
        BIT.assign(n + 1, 0);
    }
    void update(int index, int value) {
        for (; index <= n; index += index & -index)
            BIT[index] += value;
    }
    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index)
            sum += BIT[index];
        return sum;
    }
};

// Finding factors of a number
vi factors(int n) {
    vi result;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            result.pb(i);
            if (i != n / i)
                result.pb(n / i);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

// Dijkstra's algorithm
vector<pii> dijkstra(vector<vector<pii>>& graph, int start) {
    int n = graph.size();
    vi dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : graph[u]) {
            int v = edge.fi;
            int w = edge.se;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    vector<pii> result;
    for (int i = 0; i < n; ++i)
        result.pb({dist[i], i});
    return result;
}

// Prim's algorithm
int prim(vector<vector<pii>>& graph, int start) {
    int n = graph.size();
    int total_weight = 0;
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().se;
        int w = pq.top().fi;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total_weight += w;
        for (auto& edge : graph[u]) {
            int v = edge.fi;
            int weight = edge.se;
            if (!visited[v])
                pq.push({weight, v});
        }
    }
    return total_weight;
}

// Depth-First Search (DFS)
void dfs(vector<vi>& adj, vi& visited, int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(adj, visited, v);
    }
}

// Breadth-First Search (BFS)
void bfs(vector<vi>& adj, vi& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}

// Fast Exponential (a^b % mod)
ll fast_exp(ll a, ll b, ll mod) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

// Extended Euclidean Algorithm (ax + by = gcd(a, b))
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Chinese Remainder Theorem
ll chinese_remainder(vector<ll>& num, vector<ll>& rem) {
    ll prod = 1;
    for (ll n : num)
        prod *= n;
    
    ll result = 0;
    for (int i = 0; i < num.size(); ++i) {
        ll pp = prod / num[i];
        ll inv, y;
        extended_gcd(pp, num[i], inv, y);
        result += rem[i] * inv * pp;
    }
    
    return result % prod;
}
void solve(){
    
    
}

int main() {
    fast_io
    
    // Input and Output
    int t;
    cin >> t;
    while (t--) {
        solve();
      
    }
    
    return 0;
}
