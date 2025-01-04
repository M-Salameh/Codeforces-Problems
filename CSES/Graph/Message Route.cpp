#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define mid (l+r)/2
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set(X) tree<X, null_type,less_equal<X>, rb_tree_tag,tree_order_statistics_node_update>
///#define int int_fast64_t

using namespace std;
using namespace __gnu_pbds;

const int_fast64_t inf = 2e12+1;
const int NN = 2e5+1;
const int mod = 1e9+7;
int tc=1;
int n , m;

vector<int> adj[NN];
int parent[NN] , dist[NN];

void solve()
{
    queue<int> bfs;

    bfs.push(1);
    dist[1] = 0;

    while(bfs.size())
    {
        int u = bfs.front();
        bfs.pop();
        for (int& v : adj[u])
        {
            if (dist[v] <= dist[u] + 1) continue;
            dist[v] = 1 + dist[u];
            parent[v] = u;
            bfs.push(v);
        }
    }
    if (n == 1)
    {
        cout << 1 << endl << 1 ;
        return;
    }
    if (dist[n] == mod)
    {
        cout << "IMPOSSIBLE" <<endl;
        return;
    }
    vector<int> trace;
    int dest = n;
    while (dest)
    {
        trace.push_back(dest);
        dest = parent[dest];
    }
    reverse(all(trace));
    cout << trace.size() << endl;
    for (int& i : trace) cout << i << " ";

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        for (int i=1 ; i<=m ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=1 ; i<=n ; i++)
        {
            dist[i] = mod;
            parent[i] = 0;
        }
        solve();
    }

    return 0;
}


