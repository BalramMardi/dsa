#include <iostream>
#include <vector>

#include <cmath>
#include <algorithm>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;


#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fora(i, a, n) for(ll i = a; i < n; i++)
#define readi(e) int e; cin >> e
#define readl(e) ll e; cin >> e
#define reads(e) string e; cin >> e
#define T int tt; cin >> tt; while(tt--)
#define print(z) cout<< z << endl;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int count=0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    int maxd=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>0 and b[i]>0){
            count++;
            
            maxd=max(count,maxd);
        }
        else{
            count=0;
        }
    }
    
    cout << maxd << endl;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 int tc;
cin >> tc;
for (int t = 1; t <= tc; t++) {
solve();
}
}

